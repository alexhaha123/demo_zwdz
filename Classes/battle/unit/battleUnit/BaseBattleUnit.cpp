//
//  BaseBattleUnit.cpp
//  zwdz
//
//  Created by zhouzhan on 17/6/9.
//
//

#include "BaseBattleUnit.h"
#include "BattleManager.h"
#include "GIDFactory.h"
#include "battleDefine.h"

BaseBattleUnit::BaseBattleUnit():m_animatinCallback(nullptr)
{
}

BaseBattleUnit::~BaseBattleUnit()
{
    CC_SAFE_RELEASE(this->m_unitBaseData);
}

void BaseBattleUnit::initData(UnitBaseData* unitdata)
{
    this->m_unitBaseData = unitdata;
    CC_SAFE_RETAIN(unitdata);
}

void BaseBattleUnit::initView()
{
    //根据unitdata创建view相关内容
    std::string resfile = this->m_unitBaseData->res_name;
    
    this->m_animationSpine = ZWSpine::create(std::string(resfile).append(".json"),std::string(resfile).append(".atlas"),0.25);
    this->addChild(m_animationSpine);
    this->m_animationSpine->setFinishEventListener([&](int trackIndex, int loopCount){
        this->shootBullet(trackIndex, loopCount);
    });
    this->setLogicAnchorPoint(0.5, 0.5);
    this->setCollideRect(0, 0, this->m_unitBaseData->m_collideRect.size.width,  this->m_unitBaseData->m_collideRect.size.height);
    
}

void BaseBattleUnit::update(float dt)
{
    MapObject::update(dt);
    
    //碰撞检测
    if (this->getUnitBaseData()->m_UnitType == KObjType::KObjFlyObj) {
        collideTest(dt);

    }
    
    //死亡检测
    this->testDeath(dt);
}

void BaseBattleUnit::playAction(int act_id)
{
    std::string actName = this->getUnitBaseData()->getAniNameByActId(act_id);
    this->m_animationSpine->play(actName);
}

void BaseBattleUnit::playOnce(int act_id)
{
    std::string actName = this->getUnitBaseData()->getAniNameByActId(act_id);
    if (this->m_animationSpine) {
        this->m_animationSpine->play(actName, 0);
    }
}

void BaseBattleUnit::addToLand(Node* land)
{
    if (land) {
        land->addChild(this);
    }
    
}

void BaseBattleUnit::removeFromLand()
{
    this->runAction(RemoveSelf::create());
    
}

void BaseBattleUnit::shootBullet(int, int)
{
    if (this->getUnitBaseData()->m_configId == UnitConfId::WANDOU) {
        int gid = GIDFactory::getInstance()->getNextGid();
        BattleManager::getInstance()->createBullet(gid, 3);
        BaseBattleUnit* bullet = BattleManager::getInstance()->createBulletSprite(gid);
        if (this->getUnitBaseData()->m_unitGroup == UnitGroup::WE) {
            bullet->setSpeed(Vec2(0, 0.5));
            bullet->getUnitBaseData()->m_unitGroup = UnitGroup::WE;
            bullet->setPosition(0, 40);
        }else if(this->getUnitBaseData()->m_unitGroup == UnitGroup::ENERMY)
        {
            bullet->setSpeed(Vec2(0, -0.5));
            bullet->getUnitBaseData()->m_unitGroup = UnitGroup::ENERMY;
            bullet->setPosition(0, -40);
        }
        bullet->addToLand(this);
        
    }
}

bool BaseBattleUnit::isInScreen()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point worldpos = this->getParent()->convertToWorldSpace(this->getPosition());
    
    bool ret = true;
    if (worldpos.y > visibleSize.height or worldpos.y < 0) {
        ret = false;
    }
    return ret;
}

void BaseBattleUnit::collideTest(float dt)
{
    Rect collideRect = this->getWorldCollideRect();
    int unitGroup = this->getUnitBaseData()->m_unitGroup;

    
    if (unitGroup == UnitGroup::ENERMY) {
        //敌方子弹
        std::map<int, BaseBattleUnit*> friendUnits = UnitManager::getInstance()->getAllFriendUnits();
        collideLogic(collideRect, friendUnits);

    }else if(unitGroup == UnitGroup::WE)
    {
        std::map<int, BaseBattleUnit*> enemyUnits = UnitManager::getInstance()->getAllEnemyUnits();
        collideLogic(collideRect, enemyUnits);
    }
    
    if (not isInScreen()) {
        this->runAction(CallFunc::create([&](){
            BattleManager::getInstance()->removeBattleUnit(this->getUnitBaseData()->m_Gid);}));
        
    }
}

void BaseBattleUnit::collideLogic(Rect collideRect, std::map<int, BaseBattleUnit*> unitsMap)
{
    for (auto unit : unitsMap) {
        
        if (unit.second->getWorldCollideRect().intersectsRect(collideRect)) {
            CCLOG("+++++++collide");
            //非子弹减血
            FightPropData* fightprop = unit.second->getUnitBaseData()->getFightPropData();
            fightprop->setPropValue(FightProp::HP, fightprop->getPropValue(FightProp::HP)-this->getUnitBaseData()->getFightPropData()->getPropValue(FightProp::ATTACK));
            
            this->runAction(CallFunc::create([&](){
                BattleManager::getInstance()->removeBattleUnit(this->getUnitBaseData()->m_Gid);
                
            }));
            
        }
    }
}

void BaseBattleUnit::testDeath(float dt)
{
    if (this->getUnitBaseData()->getFightPropData()->getPropValue(FightProp::HP) <= 0) {
        this->runAction(CallFunc::create([&](){
            BattleManager::getInstance()->removeBattleUnit(this->getUnitBaseData()->m_Gid);
        }));
    }
}

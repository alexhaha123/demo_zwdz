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
    this->setLogicAnchorPoint(0.5, 0);
    this->setCollideRect(0, 0, this->m_unitBaseData->m_collideRect.size.width,  this->m_unitBaseData->m_collideRect.size.height);
    
}

void BaseBattleUnit::update(float dt)
{
    MapObject::update(dt);
    
    //检测死亡条件
    if (not isInScreen()) {
        this->runAction(CallFunc::create([&](){
        BattleManager::getInstance()->removeBattleUnit(this->getUnitBaseData()->m_Gid);}));
        
    }
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
        if (this->getUnitBaseData()->m_UnitType == UnitGroup::WE) {
            bullet->setSpeed(Vec2(0, 1));
        }else if(this->getUnitBaseData()->m_UnitType == UnitGroup::ENERMY)
        {
            bullet->setSpeed(Vec2(0, -1));
        }
        bullet->addToLand(this);
    }
}

bool BaseBattleUnit::isInScreen()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point worldpos = this->getParent()->convertToWorldSpace(this->getPosition());
    
    bool ret = true;
    if (worldpos.y > visibleSize.height-200 or worldpos.y < 0) {
        ret = false;
    }
    return ret;
}

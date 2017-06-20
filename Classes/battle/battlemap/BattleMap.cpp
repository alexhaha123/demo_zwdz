//
//  BattleMap.cpp
//  zwdz
//
//  Created by zhouzhan on 17/6/6.
//
//

#include "BattleMap.h"
#include <cstdio>
#include "UIloader.h"
#include "ZWSpine.h"
#include "MapTouchLayer.h"
#include "DataManager.h"
#include "UnitManager.h"
#include "GIDFactory.h"
#include "BattleManager.h"

BattleMap::BattleMap():m_battleMap(nullptr)
    ,m_sceneid(0)
{
    
}

BattleMap::~BattleMap()
{
    for (std::vector<MapTile*>::iterator ite = vec_mapTile.begin(); ite!= vec_mapTile.end(); ++ite) {
        delete *ite;
    }
}

void BattleMap::onEnter()
{
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto eventlistener = EventListenerCustom::create("DRAG_CARD_END_EVENT", CC_CALLBACK_1(BattleMap::addBattleUnitTest, this));
    dispatcher->addEventListenerWithSceneGraphPriority(eventlistener, this);
    
    Layer::onEnter();
    this->initMap();
    
    this->start();
}

void BattleMap::onExit()
{
    
}

void BattleMap::initMap()
{
    //数据，加载哪张地图
    char filename[128];
    sprintf(filename, "res/map/map%02d/map%02d.csb", m_sceneid,  m_sceneid);
    CCAssert(m_sceneid != 0, "you must initScene first");
    m_battleMap = UIloader::load(filename);
    this->addChild(m_battleMap);
    this->parserMap(m_battleMap);
    this->addChild(MapTouchLayer::create());
    this->start();
}

void BattleMap::parserMap(Node* root)
{
    auto children = root->getChildren();
    for (auto child:children) {
        if (child->getName() == "Node_land_1"){
            auto subChildren1 = child->getChildren();
            for (auto& subchild:subChildren1) {
                MapTile* tile = new MapTile((ui::Widget*)subchild);
                tile->setTileDirection(MapTileDirection::UP);
                vec_mapTile.push_back(tile);
            }
        }
        
        if (child->getName() == "Node_land_2"){
            auto subChildren1 = child->getChildren();
            for (auto& subchild:subChildren1) {
                MapTile* tile = new MapTile((ui::Widget*)subchild);
                tile->setTileDirection(MapTileDirection::Down);
                vec_mapTile.push_back(tile);
            }
        }
    }
    
    CCLOG("vec.count = %lu", vec_mapTile.size());
}

void BattleMap::start()
{
    Director::getInstance()->getScheduler()->schedule([&](float dt){this->update(dt);}, this, 1/30.0f, false,"BattleMapUpdate");
}

void BattleMap::addBattleUnitTest(EventCustom* event)
{
    Vec2* pos = (Vec2*)event->getUserData();
    CCLOG("%s, pos = (%.2f, %.2f)", event->getEventName().c_str(), pos->x, pos->y);
    for (auto tile : vec_mapTile) {
        auto ret = tile->getWorldRect();
        if (ret.containsPoint(Vec2(pos->x, pos->y))) {
            CCLOG("rect(%.2f, %.2f, %.2f, %.2f)", ret.origin.x, ret.origin.y, ret.size.width, ret.size.height);
            BaseBattleUnit* unit = nullptr;
            
            if (tile->getTileDirection() == MapTileDirection::UP)
            {
                unit = createEnemyByType(UnitConfId::WANDOU);
            }else
            {
                unit = createFriendByType(UnitConfId::WANDOU);
            }
            
            unit->setPosition(Vec2((tile)->getTileSize().width/2, (tile)->getTileSize().height/2));

            unit->addToLand(tile->getmapTile());
        }
    }
}

BaseBattleUnit* BattleMap::createEnemyByType(int type)
{
    int  gid = GIDFactory::getInstance()->getNextGid();
    CCLOG("gid = %d", gid);
    UnitBaseData* unit_data = DataManager::getInstance()->createMonster(gid, type);
    unit_data->m_UnitType = UnitGroup::ENERMY;
    
    BaseBattleUnit* unit = BattleManager::getInstance()->createEnemySprite(gid);
    unit->playAction(AnimationName::ANI_NAME_ATTACK_ENEMY);
    
    return unit;
}

BaseBattleUnit* BattleMap::createFriendByType(int type)
{
    int gid = GIDFactory::getInstance()->getNextGid();
    CCLOG("gid = %d", gid);
    UnitBaseData* unit_data = DataManager::getInstance()->createFriend(gid, type);
    unit_data->m_UnitType = UnitGroup::WE;
    
    BaseBattleUnit* unit = BattleManager::getInstance()->createFriendSprite(gid);
    unit->playAction(AnimationName::ANI_NAME_ATTACK);
    
    return unit;
}

void BattleMap::update(float dt)
{
    UnitManager::getInstance()->update(dt);
}

void BattleMap::finish()
{
    
}

void BattleMap::updateUnit(float dt)
{
    
}

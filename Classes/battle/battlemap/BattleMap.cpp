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
    auto eventlistener = EventListenerCustom::create("TEST", CC_CALLBACK_1(BattleMap::test, this));
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
    //test
//    for (std::vector<MapTile*>::iterator ite = vec_mapTile.begin(); ite != vec_mapTile.end(); ++ite) {
//        ZWSpine* sp = ZWSpine::create("animation/spine/wandou/wandou.json", "animation/spine/wandou/wandou.atlas", 0.25f);
//        auto dir = (*ite)->getTileDirection();
//        std::string actionname = "zheng_attack";
//        if(dir == MapTileDirection::Down){
//            actionname = "fan_attack";
//        }
//        sp->play(actionname, true);
//        sp->setPosition(Vec2((*ite)->getTileSize().width/2, (*ite)->getTileSize().height/2));
//        (*ite)->getmapTile()->addChild(sp);
//    }
    
}

bool BattleMap::onTouchBegan(Touch *touch, Event *unused_event)
{
    CCLOG("ontouchbegin");
    return true;
}
void BattleMap::onTouchMoved(Touch *touch, Event *unused_event)
{
    
}
void BattleMap::onTouchEnded(Touch *touch, Event *unused_event)
{
    Vec2 pos = Director::getInstance()->convertToGL(touch->getLocation());
    for (auto tile : vec_mapTile) {
        auto ret = tile->getWorldRect();
        if (ret.containsPoint(pos)) {
            CCLOG("rect(%.2f, %.2f, %.2f, %.2f)", ret.origin.x, ret.origin.y, ret.size.width, ret.size.height);
        }
    }
    
}

void BattleMap::test(EventCustom* event)
{
    Vec2* pos = (Vec2*)event->getUserData();
    CCLOG("%s, pos = (%.2f, %.2f)", event->getEventName().c_str(), pos->x, pos->y);
    for (auto tile : vec_mapTile) {
        auto ret = tile->getWorldRect();
        if (ret.containsPoint(Vec2(pos->x, pos->y))) {
            CCLOG("rect(%.2f, %.2f, %.2f, %.2f)", ret.origin.x, ret.origin.y, ret.size.width, ret.size.height);
            ZWSpine* sp = ZWSpine::create("animation/spine/wandou/wandou.json", "animation/spine/wandou/wandou.atlas", 0.25f);
            auto dir = (tile)->getTileDirection();
            std::string actionname = "zheng_attack";
            if(dir == MapTileDirection::Down){
                actionname = "fan_attack";
            }
            sp->play(actionname, true);
            sp->setPosition(Vec2((tile)->getTileSize().width/2, (tile)->getTileSize().height/2));
            (tile)->getmapTile()->addChild(sp);
        }
    }
}

void BattleMap::update(float dt)
{
    
}

void BattleMap::finish()
{
    
}

void BattleMap::updateUnit(float dt)
{
    
}

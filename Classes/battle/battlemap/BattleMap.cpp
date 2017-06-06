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
    for (std::vector<MapTile*>::iterator ite = vec_mapTile.begin(); ite != vec_mapTile.end(); ++ite) {
        ZWSpine* sp = ZWSpine::create("animation/spine/wandou/wandou.json", "animation/spine/wandou/wandou.atlas", 0.35f);
        auto dir = (*ite)->getTileDirection();
        std::string actionname = "zheng_attack";
        if(dir == MapTileDirection::Down){
            actionname = "fan_attack";
        }
        sp->play(actionname, true);
        (*ite)->getmapTile()->addChild(sp);
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

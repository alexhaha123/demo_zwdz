//
//  BattleMap.h
//  zwdz
//
//  Created by zhouzhan on 17/6/6.
//
//

#ifndef BattleMap_h
#define BattleMap_h

#include "MapTile.h"
#include <vector>
USING_NS_CC;

class BattleMap : public Layer
{
public:
    BattleMap();
    ~BattleMap();
    
    virtual void onEnter();
    virtual void onExit();
    
    inline void initSceneId(unsigned int sceneid){this->m_sceneid = sceneid;}
    
    //游戏逻辑帧
    virtual void update(float dt);
    //逻辑开始
    void start();
    //逻辑结束
    void finish();
    //初始化地图
    void initMap();
    
    void updateUnit(float dt);
    
private:
    void parserMap(Node* root);

private:
    Node* m_battleMap;
    unsigned int m_sceneid;
    std::vector<MapTile*> vec_mapTile;
};
#endif /* BattleMap_h */

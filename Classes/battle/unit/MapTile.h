//
//  MapTile.h
//  zwdz
//
//  Created by zhouzhan on 17/6/6.
//
//

#ifndef MapTile_h
#define MapTile_h

#include "CocosGUI.h"
#include "../battleDefine.h"
using namespace cocos2d;

class MapTile{
public:
    MapTile(ui::Widget* mapTile);
    
    
private:
    CC_SYNTHESIZE(MapTileDirection, dir, TileDirection);
    CC_SYNTHESIZE(ui::Widget*, m_mapTile, mapTile);
    CC_SYNTHESIZE(int, m_UnitGid, unitGid);
};

#endif /* MapTile_h */

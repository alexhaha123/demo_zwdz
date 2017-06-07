//
//  MapTile.cpp
//  zwdz
//
//  Created by zhouzhan on 17/6/6.
//
//

#include "MapTile.h"

MapTile::MapTile(ui::Widget* mapTile)
    :m_mapTile(mapTile),
    m_UnitGid(0),
    dir(MapTileDirection::None)
{
    m_tileSize = m_mapTile->getContentSize();
    Vec2 worldPos = Director::getInstance()->convertToGL(m_mapTile->getPosition());
    m_worldRect = Rect(worldPos.x-m_tileSize.width/2, worldPos.y-m_tileSize.height/2, m_tileSize.width, m_tileSize.height);
}

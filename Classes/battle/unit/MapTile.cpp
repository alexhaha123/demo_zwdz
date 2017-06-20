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
    Vec2 worldPos =  m_mapTile->getParent()->convertToWorldSpace(m_mapTile->getPosition());
    m_worldRect = Rect(worldPos.x, worldPos.y, m_tileSize.width, m_tileSize.height);
}

bool MapTile::isTileNull()
{
    bool ret = false;
    if (m_mapTile->getChildrenCount() != 0) {
        ret = true;
    }
    return  ret;
}

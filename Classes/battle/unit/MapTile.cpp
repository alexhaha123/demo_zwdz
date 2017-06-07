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
    Vec2 worldPos =  m_mapTile->getParent()->convertToWorldSpace(m_mapTile->getPosition());//Director::getInstance()->convertToGL(m_mapTile->getPosition());
    Vec2 anc = m_mapTile->getAnchorPoint();
//    CCLOG("anchorpoint = (%.2f, %.2f)", anc.x, anc.y);
    m_worldRect = Rect(worldPos.x, worldPos.y, m_tileSize.width, m_tileSize.height);
}

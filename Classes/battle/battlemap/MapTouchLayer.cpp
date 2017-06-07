//
//  MapTouchLayer.cpp
//  zwdz
//
//  Created by zhouzhan on 17/6/7.
//
//

#include "MapTouchLayer.h"
bool MapTouchLayer::init()
{
    Layer::init();
    this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    this->setTouchEnabled(true);
    
    CCLOG("MapTouchLayer::init()");
    return true;
}

bool MapTouchLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
    CCLOG("ontouchbegin");
    return true;
}
void MapTouchLayer::onTouchMoved(Touch *touch, Event *unused_event)
{
    
}
void MapTouchLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
//    Vec2 pos = Director::getInstance()->convertToGL(touch->getLocation());
//    for (auto tile : vec_mapTile) {
//        auto ret = tile->getWorldRect();
//        if (ret.containsPoint(pos)) {
//            CCLOG("rect(%.2f, %.2f, %.2f, %.2f)", ret.origin.x, ret.origin.y, ret.size.width, ret.size.height);
//        }
//    }
    
    Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("TEST");
    
}

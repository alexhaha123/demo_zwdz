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
    Vec2 pos = touch->getLocation();
    CCLOG("(%.2f,%.2f)", pos.x, pos.y);
    Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("DRAG_CARD_END_EVENT", &pos);
    
}

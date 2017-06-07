//
//  MapTouchLayer.h
//  zwdz
//
//  Created by zhouzhan on 17/6/7.
//
//

#ifndef MapTouchLayer_h
#define MapTouchLayer_h

#include "cocos2d.h"
#include "BattleMap.h"
USING_NS_CC;

class MapTouchLayer : public Layer
{
public:
    CREATE_FUNC(MapTouchLayer);
    virtual bool init();
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    
    friend void BattleMap::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
};

#endif /* MapTouchLayer_h */

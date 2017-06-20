//
//  MapObject.h
//  zwdz
//
//  Created by zhouzhan on 12/6/17.
//
//

#ifndef MapObject_h
#define MapObject_h

#include <cocos2d.h>
USING_NS_CC;

class MapObject : public Node
{
public:
    MapObject();
    
    virtual ~MapObject();
    
    virtual void update(float dt);
    
    //position about interface
    virtual void setPosition(float x, float y);
    
    virtual void setPosition(const Vec2 &position);
    
    virtual void setPositionWithoutAdjust(float x, float y);
    
//    const Vec2 getNextFramePosition(float dt);
    
    const Vec2 getWorldPosition();
    
    //collide about interface
    const Rect& getCollideRect() {return  this->m_oCollideRect;}
    
    virtual void setCollideRect(float x, float y, float width, float height);
    
    void setLogicAnchorPoint(float x, float y);

    void setLogciAnchorPoint(Vec2 pos);
    
    int getObjType(){return m_iObjType;}
    
    float getSlowFactor() { return this->m_slowFactor; }
    
    void setSlowFactor(float slowfactor) {this->m_slowFactor = slowfactor;}
    
    void setSpeed(const Vec2& speed){this->m_oMovePt = speed;};
    
protected:
    virtual void updatePosition(float dt);
    
    virtual void updateSpeed(float dt);
    
    virtual Point adjustPosition(float, float);

private:
    int m_iObjType;
    
    float m_slowFactor;
    
    Vec2 m_oMovePt;
    Vec2 m_oMoveAddPt;
    
    Rect m_oCollideRect;
    Vec2 m_oLogicAnchorPoint;
    
    CC_SYNTHESIZE(bool, m_bConsistWithScreen, ConsistWithScreen);
};

#endif /* MapObject_h */

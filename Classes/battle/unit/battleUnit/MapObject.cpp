//
//  MapObject.cpp
//  zwdz
//
//  Created by zhouzhan on 12/6/17.
//
//

#include "MapObject.h"
#include "battleDefine.h"

MapObject::MapObject():m_iObjType(KObjType::KObjInvalid),
m_bConsistWithScreen(false)
{
    m_oMovePt = Vec2::ZERO;
    m_oMoveAddPt = Vec2::ZERO;
    m_oCollideRect = Rect::ZERO;
    m_oLogicAnchorPoint = Vec2::ZERO;
    m_slowFactor = 0.5f;
}

MapObject::~MapObject()
{
    
}

void MapObject::update(float dt)
{
    this->updateSpeed(dt);
    this->updatePosition(dt);
}

Point MapObject::adjustPosition(float x, float y)
{
    return Point(x, y);
}

void MapObject::setPosition(float x, float y)
{
    Point pos = this->adjustPosition(x, y);
    x = pos.x;
    y = pos.y;
    
    setPositionWithoutAdjust(x, y);
}

void MapObject::setPosition(const Vec2 &position)
{
    this->setPosition(position.x, position.y);
}

void MapObject::setPositionWithoutAdjust(float x, float y)
{
    Node::setPosition(x, y);
    x = x - this->m_oCollideRect.size.width * this->m_oLogicAnchorPoint.x;
    y = y - this->m_oCollideRect.size.height * this->m_oLogicAnchorPoint.y;
    
    this->m_oCollideRect.origin = Vec2(x, y);
}

void MapObject::updatePosition(float dt)
{
    float deltaTime = dt * 1000.f;
    
    Point pt = this->getPosition();
    
    float fslowfactor = this->getSlowFactor();
    
    float x = pt.x + this->m_oMovePt.x * deltaTime * fslowfactor - 0.5 * this->m_oMoveAddPt.x * deltaTime * deltaTime * fslowfactor;
    float y = pt.y + this->m_oMovePt.y * deltaTime * fslowfactor - 0.5 * this->m_oMoveAddPt.y * deltaTime * deltaTime * fslowfactor;
    
    this->setPosition(x, y);
}

const Vec2 MapObject::getWorldPosition()
{
    Point worldPos = Point::ZERO;
    Point pos = this->getPosition();
    if (this->getParent()) {
        worldPos = this->getParent()->convertToWorldSpace(pos);
    }
    return worldPos;
}

void MapObject::setCollideRect(float x, float y, float width, float height)
{
    this->m_oCollideRect.size.width = width;
    this->m_oCollideRect.size.height = height;
    
    this->setPositionWithoutAdjust(x, y);
}

const Rect MapObject::getWorldCollideRect()
{
    Vec2 worldRectOrigin = Vec2::ZERO;
    if (this->getParent()) {
        worldRectOrigin = this->getParent()->convertToWorldSpace(this->m_oCollideRect.origin);
    }
    
    return Rect(worldRectOrigin.x, worldRectOrigin.y, this->m_oCollideRect.size.width, this->m_oCollideRect.size.height);
}

void MapObject::setLogicAnchorPoint(float x, float y)
{
    this->m_oLogicAnchorPoint = Vec2(x, y);
}

void MapObject::setLogciAnchorPoint(Vec2 pos)
{
    this->m_oLogicAnchorPoint = pos;
}

void MapObject::updateSpeed(float dt)
{
    float deltaTime = dt * 1000;
    this->m_oMovePt.x += this->m_oMoveAddPt.x * deltaTime;
    this->m_oMovePt.y += this->m_oMoveAddPt.y * deltaTime;
}

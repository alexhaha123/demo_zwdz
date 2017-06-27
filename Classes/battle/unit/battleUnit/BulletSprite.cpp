//
//  BulletSprite.cpp
//  zwdz
//
//  Created by zhouzhan on 18/6/17.
//
//

#include "BulletSprite.h"
void BulletSprite::initView()
{
    std::string resName = "guoyuan_wandou_zidan.png";
    Sprite* sp = Sprite::create();
    sp->initWithFile(resName);
    this->addChild(sp);
    this->setLogicAnchorPoint(0.5, 0.5);
    this->setCollideRect(0, 0, this->m_unitBaseData->m_collideRect.size.width,  this->m_unitBaseData->m_collideRect.size.height);

}

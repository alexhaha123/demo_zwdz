//
//  BulletData.cpp
//  zwdz
//
//  Created by zhouzhan on 18/6/17.
//
//

#include "BulletData.h"
#include "JsonReader.h"
#include "ToolFunction.h"
#include "battleDefine.h"

BulletData::BulletData()
{
    this->m_UnitType = KObjType::KObjFlyObj;
}

BulletData::~BulletData()
{
    
}

bool BulletData::init(int gid, int configID)
{
    bool ret = true;
    
    this->m_Gid = gid;
    this->m_configId = configID;
    
    this->initData();
    
    return ret;
}

bool BulletData::initData()
{
    std::string configName = JsonReader::getInstance()->getStringByKey("confID.json", ToolFunction::convertIntToString(this->m_configId));
    
    //读表取值
    int attack = JsonReader::getInstance()->getIntByKey(configName, "attack");
    int defence = JsonReader::getInstance()->getIntByKey(configName, "defence");
    int hp = JsonReader::getInstance()->getIntByKey(configName, "hp");
    int colRectWidth = JsonReader::getInstance()->getIntByKey(configName, "collideRectWidth");
    int colRectHeight = JsonReader::getInstance()->getIntByKey(configName, "collideRectHeight");
    std::string filepath = JsonReader::getInstance()->getStringByKey(configName, "res");
    
    //赋值
    this->getFightPropData()->setPropValue(FightProp::ATTACK, attack);
    this->getFightPropData()->setPropValue(FightProp::DEFENCE, defence);
    this->getFightPropData()->setPropValue(FightProp::HP, hp);
    this->res_name = filepath;
    this->m_collideRect.size.width = colRectWidth;
    this->m_collideRect.size.height = colRectHeight;
    
    return true;
}

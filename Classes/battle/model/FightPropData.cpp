//
//  FightPropData.cpp
//  zwdz
//
//  Created by zhouzhan on 17/6/9.
//
//

#include "FightPropData.h"
FightPropData::FightPropData()
{
    //初始化基础属性 0 
    for (int i = 0; i < FightProp::MAX; ++i) {
        this->m_fightPropMap.insert(std::pair<int, int>(i, 0));
    }
}

FightPropData::~FightPropData()
{
    
}

void FightPropData::setPropValue(FightProp key, int value)
{
    FightPropMap::iterator ite =  m_fightPropMap.find(key);
    if (ite != m_fightPropMap.end()) {
        ite->second = value;
    }else{
        this->m_fightPropMap.insert(std::pair<int, int>(key, value));
    }
}

int  FightPropData::getPropValue(FightProp key)
{
    int ret = 0;
    FightPropMap::iterator ite = m_fightPropMap.find(key);
    if (ite != m_fightPropMap.end()) {
        ret = ite->second;
    }
    return ret;
}

void FightPropData::addPropValue(FightProp key, int value)
{
    int oldValue = 0;
    FightPropMap::iterator ite = m_fightPropMap.find(key);
    if (ite != m_fightPropMap.end()) {
        oldValue = ite->second;
        setPropValue(key, oldValue+value);
    }
}

void FightPropData::removePropValue(FightProp key, int value)
{
    int oldValue = 0;
    FightPropMap::iterator ite = m_fightPropMap.find(key);
    if (ite != m_fightPropMap.end()) {
        oldValue = ite->second;
    }
    
    if (oldValue > 0) {
        setPropValue(key, oldValue - value);
    }
}

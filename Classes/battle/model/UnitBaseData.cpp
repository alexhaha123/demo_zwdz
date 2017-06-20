//
//  UnitBaseData.cpp
//  zwdz
//
//  Created by zhouzhan on 17/6/9.
//
//

#include "UnitBaseData.h"
#include "battleDefine.h"
UnitBaseData::UnitBaseData():m_Gid(0),m_UnitType(0)
{
    m_FightPropData = new FightPropData;
    m_animationMap = new AnimationMap();
    for (int i = 1; i < AnimationName::ANI_NAME_MAX; i++) {
        m_animationMap->insert(std::pair<int, std::string>(i, ""));
    }
}

UnitBaseData::~UnitBaseData()
{
    delete  m_FightPropData;
    m_FightPropData = nullptr;
    
    delete m_animationMap;
    m_animationMap = nullptr;
}

std::string UnitBaseData::getAniNameByActId(int act_id)
{
    std::string ret = "";
    AnimationMap::iterator ite = m_animationMap->find(act_id);
    if (ite != m_animationMap->end()) {
        ret = ite->second;
    }
    return ret;
}

void UnitBaseData::setAniNameByActId(int act_id, const std::string& name)
{
    AnimationMap::iterator ite = m_animationMap->find(act_id);
    if (ite != m_animationMap->end()) {
        ite->second = name;
    }
}

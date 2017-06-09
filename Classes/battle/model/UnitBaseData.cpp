//
//  UnitBaseData.cpp
//  zwdz
//
//  Created by zhouzhan on 17/6/9.
//
//

#include "UnitBaseData.h"
UnitBaseData::UnitBaseData():m_Gid(0),m_UnitType(0)
{
    m_FightPropData = new FightPropData;
}

UnitBaseData::~UnitBaseData()
{
    delete  m_FightPropData;
    m_FightPropData = nullptr;
}

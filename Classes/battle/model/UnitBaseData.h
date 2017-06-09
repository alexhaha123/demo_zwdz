//
//  UnitBaseData.h
//  zwdz
//
//  Created by zhouzhan on 17/6/9.
//
//

#ifndef UnitBaseData_h
#define UnitBaseData_h

#include <cocos2d.h>
#include "FightPropData.h"

USING_NS_CC;

class UnitBaseData : public Ref
{
public:
    UnitBaseData();
    virtual ~UnitBaseData();
    
public:
    int m_Gid;
    int m_UnitType;
    
private:
    CC_SYNTHESIZE(FightPropData*, m_FightPropData, FightPropData);
};

#endif /* UnitBaseData_h */

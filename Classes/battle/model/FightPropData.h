//
//  FightPropData.h
//  zwdz
//
//  Created by zhouzhan on 17/6/9.
//
//

#ifndef FightPropData_h
#define FightPropData_h

#include <map>

enum FightProp
{
    ATTACK  =   1,
    DEFENCE =   2,
    HP      =   3,
    MAX
};

typedef std::map<int, int> FightPropMap;

class FightPropData {
public:
    FightPropData();
    
    ~FightPropData();
    
    void setPropValue(FightProp key, int value);
    int  getPropValue(FightProp key);
    
    void addPropValue(FightProp key, int value);
    void removePropValue(FightProp key, int value);
    
private:
    FightPropMap m_fightPropMap;
    
};

#endif /* FightPropData_h */

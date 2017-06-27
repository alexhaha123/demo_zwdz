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
typedef std::map<int, std::string> AnimationMap;

class UnitBaseData : public Ref
{
public:
    UnitBaseData();
    
    virtual ~UnitBaseData();
    
    std::string getAniNameByActId(int act_id);
    
    void setAniNameByActId(int act_id, const std::string& name);

    void setSpeed(const Vec2& speed) {this->m_speed = speed;}
    
    Vec2 getSpeed() const {return this->m_speed;}
public:
    int m_Gid;
    int m_configId;
    int m_UnitType;
    int m_unitGroup;
    std::string res_name;
    Rect m_collideRect;
    Vec2 m_speed;
    
private:
    CC_SYNTHESIZE(FightPropData*, m_FightPropData, FightPropData);
    AnimationMap* m_animationMap;
};

#endif /* UnitBaseData_h */

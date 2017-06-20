//
//  BaseBattleUnit.h
//  zwdz
//
//  Created by zhouzhan on 17/6/9.
//
//

#ifndef BaseBattleUnit_h
#define BaseBattleUnit_h

#include "MapObject.h"
#include "ZWSpine.h"
#include "UnitBaseData.h"

typedef std::function<void(int,int) > AnimatinCallback;

class BaseBattleUnit : public MapObject
{
public:
    BaseBattleUnit();
    
    virtual ~BaseBattleUnit();
    
    virtual void update(float dt);
    
    virtual void initData(UnitBaseData*);

    virtual void initView();
    
    void playAction(int act_id);
    
    void playOnce(int act_id);
    
    virtual void addToLand(Node*);
    
    virtual void removeFromLand();
    
    virtual void shootBullet(int, int);
    
    bool isInScreen();
    
    void collideTest();
private:
    CC_SYNTHESIZE(ZWSpine*, m_animationSpine, AnimationSpine);
    CC_SYNTHESIZE(UnitBaseData*, m_unitBaseData, UnitBaseData);
    CC_SYNTHESIZE_PASS_BY_REF(AnimatinCallback, m_animatinCallback, AnimationCallback);
};

#endif /* BaseBattleUnit_h */

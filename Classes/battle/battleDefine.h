//
//  battleDefine.h
//  zwdz
//
//  Created by zhouzhan on 17/6/6.
//
//

#ifndef battleDefine_h
#define battleDefine_h

enum MapTileDirection{
    None = 0,
    UP = 1,
    Down = 2
};

enum UnitGroup{
    WE = 1,
    ENERMY = 2
};

enum UnitConfId{
    WANDOU = 1,
    JIANGUO = 2
};

enum KObjType{
    KObjInvalid = -1,
    KObjUnit = 0,
    KObjFlyObj = 1
};

enum AnimationName{
    ANI_NAME_IDLE = 1,
    ANI_NAME_ATTACK = 2,
    ANI_NAME_BEHIT = 3,
    ANI_NAME_DIE = 4,
    ANI_NAME_IDLE_ENEMY = 5,
    ANI_NAME_ATTACK_ENEMY = 6,
    ANI_NAME_BEHIT_ENEMY = 7,
    ANI_NAME_DIE_ENEMY = 8,
    ANI_NAME_MAX = 9,
};

#endif /* battleDefine_h */

//
//  BulletData.h
//  zwdz
//
//  Created by zhouzhan on 18/6/17.
//
//

#ifndef BulletData_h
#define BulletData_h

#include "UnitBaseData.h"

class BulletData : public UnitBaseData
{
public:
    BulletData();
    ~BulletData();
    
    bool init(int gid, int configID);
    
    bool initData();
    
};
#endif /* BulletData_h */

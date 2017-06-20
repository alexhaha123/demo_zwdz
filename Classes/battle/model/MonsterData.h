//
//  MonsterData.h
//  zwdz
//
//  Created by zhouzhan on 12/6/17.
//
//

#ifndef MonsterData_h
#define MonsterData_h

#include "UnitBaseData.h"

class MonsterData : public UnitBaseData
{
public:
    MonsterData();
    ~MonsterData();
    
    bool init(int gid, int configID);
    
    bool initData();
    
private:
    void parseActionName(const std::string& configname);
};
#endif /* MonsterData_h */

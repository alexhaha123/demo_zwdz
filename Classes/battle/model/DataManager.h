//
//  DataManager.h
//  zwdz
//
//  Created by zhouzhan on 12/6/17.
//
//

#ifndef DataManager_h
#define DataManager_h

#include "UnitBaseData.h"


class DataManager
{
    typedef std::map<int, UnitBaseData*> BattleUnitDatas;
    typedef std::map<int, UnitBaseData*> ButtleUnitDatas;
public:
    ~DataManager();
    static DataManager* getInstance();
    static void destroyInstance();
    
    UnitBaseData* createMonster(int gid, int configId);
    
    UnitBaseData* createFriend(int gid, int configId);
    
    UnitBaseData* createBullet(int  gid, int configId);
    
    UnitBaseData* getBattleUnitData(int gid);
    UnitBaseData* getBulletUnitData(int gid);
    
    void removeButtleData(int gid);
    void removeBattleUnitData(int gid);
    
    void removeAllBattleUnitData();
    
private:
    DataManager();
    BattleUnitDatas m_battleUnitDatas;
    ButtleUnitDatas m_bulletUnitDatas;
};

#endif /* DataManager_h */

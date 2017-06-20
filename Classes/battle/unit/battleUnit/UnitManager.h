//
//  UnitManager.h
//  zwdz
//
//  Created by zhouzhan on 14/6/17.
//
//

#ifndef UnitManager_h
#define UnitManager_h

#include "BaseBattleUnit.h"
typedef std::map<int, BaseBattleUnit*> BattleUnitMap;
typedef std::map<int, BaseBattleUnit*> BulletUnitMap;

class UnitManager {
public:
    ~UnitManager();
    static UnitManager* getInstance();
    static void destroyInstance();
    
    virtual void update(float dt);
    
    BaseBattleUnit* createEnemy(UnitBaseData* unitData);
    BaseBattleUnit* createFriend(UnitBaseData* unitData);
    BaseBattleUnit* createBullet(UnitBaseData* unitData);
    
    BaseBattleUnit* getEnemy(int gid);
    BaseBattleUnit* getFriend(int gid);
    
    BaseBattleUnit* getBattleUnitSprite(int gid);
    
    void removeUnit(int gid);
    
    bool removeFriend(int gid);
    bool removeEnemy(int gid);
    bool removeBullet(int gid);
    void removeAllUnits();
private:
    UnitManager();
    static UnitManager* sharedInstance;
    
    BattleUnitMap m_UnitFriendsMap;
    BattleUnitMap m_UnitEnemyMap;
    BulletUnitMap m_UnitBulletMap;
};

#endif /* UnitManager_h */

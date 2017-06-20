//
//  BattleManager.h
//  zwdz
//
//  Created by zhouzhan on 15/6/17.
//
//

#ifndef BattleManager_h
#define BattleManager_h

#include "DataManager.h"
#include "UnitManager.h"
#include "BaseBattleUnit.h"

class BattleManager
{
public:
    static BattleManager* getInstance();
    static void destroyInstance();
    ~BattleManager();
    
    //create data
    UnitBaseData* createEnemy(int gid, int confID);
    UnitBaseData* createFriend(int gid, int confID);
    UnitBaseData* createBullet(int gid, int confID);
    
    //create sprite
    BaseBattleUnit*		createFriendSprite(int gid);
    BaseBattleUnit*     createEnemySprite(int gid);
    BaseBattleUnit*     createBulletSprite(int gid);
    
    // get and remove sprite.
    BaseBattleUnit* getBattleUnitSprite(int gid);
    void removeBattleUnitSprite(int gid);
    
    // remove data and sprite of the unit.
    void removeBattleUnit(int gid);
    void removeAllBattleUnit();
private:
    static BattleManager* sharedInsance;
    BattleManager();

};

#endif /* BattleManager_h */

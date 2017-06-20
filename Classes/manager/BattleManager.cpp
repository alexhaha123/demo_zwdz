//
//  BattleManager.cpp
//  zwdz
//
//  Created by zhouzhan on 15/6/17.
//
//

#include "BattleManager.h"
BattleManager* BattleManager::sharedInsance = nullptr;

BattleManager::BattleManager()
{
    
}

BattleManager::~BattleManager()
{
    
}

BattleManager* BattleManager::getInstance()
{
    if (sharedInsance == nullptr) {
        sharedInsance = new BattleManager();
    }
    return sharedInsance;
}

void BattleManager::destroyInstance()
{
    if (sharedInsance) {
        delete sharedInsance;
        sharedInsance = nullptr;
    }
}

UnitBaseData* BattleManager::createEnemy(int gid, int confID)
{
    return DataManager::getInstance()->createMonster(gid, confID);
}

UnitBaseData* BattleManager::createFriend(int gid, int confID)
{
    return DataManager::getInstance()->createFriend(gid, confID);
}

UnitBaseData* BattleManager::createBullet(int gid, int confID)
{
    return DataManager::getInstance()->createBullet(gid, confID);
}

BaseBattleUnit* BattleManager::createFriendSprite(int gid)
{
    return UnitManager::getInstance()->createFriend(DataManager::getInstance()->getBattleUnitData(gid));
}

BaseBattleUnit* BattleManager::createEnemySprite(int gid)
{
    return UnitManager::getInstance()->createEnemy(DataManager::getInstance()->getBattleUnitData(gid));
}

BaseBattleUnit* BattleManager::createBulletSprite(int gid)
{
    return UnitManager::getInstance()->createBullet(DataManager::getInstance()->getBulletUnitData(gid));
}

BaseBattleUnit* BattleManager::getBattleUnitSprite(int gid)
{
    return UnitManager::getInstance()->getBattleUnitSprite(gid);
}

void BattleManager::removeBattleUnitSprite(int gid)
{
    UnitManager::getInstance()->removeUnit(gid);
}

void BattleManager::removeBattleUnit(int gid)
{
    UnitManager::getInstance()->removeUnit(gid);
    DataManager::getInstance()->removeBattleUnitData(gid);
    CCLOG("remove Battle unit sprite: %d", gid);
}

void BattleManager::removeAllBattleUnit()
{
    UnitManager::getInstance()->removeAllUnits();
    DataManager::getInstance()->removeAllBattleUnitData();
}


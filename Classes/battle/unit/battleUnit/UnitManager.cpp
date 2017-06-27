//
//  UnitManager.cpp
//  zwdz
//
//  Created by zhouzhan on 14/6/17.
//
//

#include "UnitManager.h"
UnitManager* UnitManager::sharedInstance = nullptr;

UnitManager::UnitManager()
{
    
}

UnitManager::~UnitManager()
{
    this->removeAllUnits();
}

UnitManager* UnitManager::getInstance()
{
    if (sharedInstance == nullptr) {
        sharedInstance = new UnitManager;
    }
    return sharedInstance;
}

void UnitManager::destroyInstance()
{
    if (sharedInstance) {
        delete sharedInstance;
        sharedInstance = nullptr;
    }
}

void UnitManager::update(float dt)
{
    for (BattleUnitMap::iterator ite = m_UnitFriendsMap.begin(); ite != m_UnitFriendsMap.end(); ite++) {
        ite->second->update(dt);
    }
    
    for (BattleUnitMap::iterator ite = m_UnitEnemyMap.begin(); ite != m_UnitEnemyMap.end(); ite++) {
        ite->second->update(dt);
    }
    
    for (BulletUnitMap::iterator ite = m_UnitBulletMap.begin(); ite != m_UnitBulletMap.end(); ite++) {
        ite->second->update(dt);
    }
}

BaseBattleUnit* UnitManager::createEnemy(UnitBaseData* unitData)
{
    BaseBattleUnit* pRet = nullptr;
    if (unitData) {
        BattleUnitMap::iterator ite = m_UnitEnemyMap.find(unitData->m_Gid);
        if (ite != m_UnitEnemyMap.end()) {
            pRet = ite->second;
        }else
        {
            BaseBattleUnit* enemy = new BaseBattleUnit();
            CC_SAFE_RETAIN(enemy);
            
            enemy->initData(unitData);
            enemy->initView();
            this->m_UnitEnemyMap.insert(std::pair<int, BaseBattleUnit*>(unitData->m_Gid, enemy));
            
            pRet = enemy;
        }
    }
    
    return pRet;
}

BaseBattleUnit* UnitManager::createFriend(UnitBaseData* unitData)
{
    BaseBattleUnit* pRet = nullptr;
    if (unitData) {
        BattleUnitMap::iterator ite = m_UnitFriendsMap.find(unitData->m_Gid);
        if (ite != m_UnitFriendsMap.end()) {
            pRet = ite->second;
        }else
        {
            BaseBattleUnit* friends = new BaseBattleUnit();
            CC_SAFE_RETAIN(friends);
            
            friends->initData(unitData);
            friends->initView();
            this->m_UnitFriendsMap.insert(std::pair<int, BaseBattleUnit*>(unitData->m_Gid, friends));
            
            pRet = friends;
        }
    }
    
    return pRet;
}

BaseBattleUnit* UnitManager::createBullet(UnitBaseData* unitData)
{
    BaseBattleUnit* pRet = nullptr;
    if (unitData) {
        BattleUnitMap::iterator ite = m_UnitBulletMap.find(unitData->m_Gid);
        if (ite != m_UnitBulletMap.end()) {
            pRet = ite->second;
        }else
        {
            BaseBattleUnit* bullet = new BulletSprite();
            CC_SAFE_RETAIN(bullet);
            
            bullet->initData(unitData);
            bullet->initView();
            this->m_UnitBulletMap.insert(std::pair<int, BaseBattleUnit*>(unitData->m_Gid, bullet));
            
            pRet = bullet;
        }
    }
    
    return pRet;
}

BaseBattleUnit* UnitManager::getEnemy(int gid)
{
    BaseBattleUnit* pRet = nullptr;
    BattleUnitMap::iterator ite = m_UnitEnemyMap.find(gid);
    if (ite != m_UnitEnemyMap.end()) {
        pRet = ite->second;
    }
    return pRet;
}

BaseBattleUnit* UnitManager::getFriend(int gid)
{
    BaseBattleUnit* pRet = nullptr;
    BattleUnitMap::iterator ite = m_UnitFriendsMap.find(gid);
    if (ite != m_UnitFriendsMap.end()) {
        pRet = ite->second;
    }
    return pRet;

}

BaseBattleUnit* UnitManager::getBattleUnitSprite(int gid)
{
    BaseBattleUnit* unit = nullptr;
    do {
        BattleUnitMap::iterator ite = m_UnitFriendsMap.find(gid);
        if (ite != m_UnitFriendsMap.end()) {
            unit = ite->second;
            break;
        }
        
        ite = m_UnitEnemyMap.begin();
        if (ite != m_UnitEnemyMap.end()) {
            unit = ite->second;
            break;
        }
        
    } while (false);
    return unit;
}

bool UnitManager::removeFriend(int gid)
{
    bool pRet = false;
    BattleUnitMap::iterator ite = m_UnitFriendsMap.find(gid);
    if (ite != m_UnitFriendsMap.end()) {
        ite->second->removeFromLand();
        CC_SAFE_RELEASE_NULL(ite->second);
        
        m_UnitFriendsMap.erase(ite);
        pRet = true;
    }
    return pRet;
}

bool UnitManager::removeEnemy(int gid)
{
    bool pRet = false;
    BattleUnitMap::iterator ite = m_UnitEnemyMap.find(gid);
    if (ite != m_UnitEnemyMap.end()) {
        ite->second->removeFromLand();
        CC_SAFE_RELEASE_NULL(ite->second);
        
        m_UnitEnemyMap.erase(ite);
        pRet = true;
    }
    return pRet;
}

bool UnitManager::removeBullet(int gid)
{
    bool pRet = false;
    BulletUnitMap::iterator ite = m_UnitBulletMap.find(gid);
    if (ite != m_UnitBulletMap.end()) {
        ite->second->removeFromLand();
        CC_SAFE_RELEASE_NULL(ite->second);
        
        m_UnitBulletMap.erase(ite);
        pRet = true;
    }
    return pRet;

}

void UnitManager::removeAllUnits()
{
    for (BattleUnitMap::iterator ite = m_UnitEnemyMap.begin(); ite!=m_UnitEnemyMap.end(); ite++) {
        ite->second->removeFromLand();
        CC_SAFE_RELEASE_NULL(ite->second);
    }
    
    for (BattleUnitMap::iterator ite = m_UnitFriendsMap.begin(); ite != m_UnitFriendsMap.end(); ite++) {
        ite->second->removeFromLand();
        CC_SAFE_RELEASE_NULL(ite->second);
    }
    
    for (BulletUnitMap::iterator ite = m_UnitBulletMap.begin(); ite != m_UnitBulletMap.end(); ite++) {
        ite->second->removeFromLand();
        CC_SAFE_RELEASE_NULL(ite->second);
    }
    
    this->m_UnitEnemyMap.clear();
    this->m_UnitFriendsMap.clear();
    this->m_UnitBulletMap.clear();
}

void UnitManager::removeUnit(int gid)
{
    if (this->removeEnemy(gid)) {
        return;
    }
    
    if (this->removeFriend(gid)) {
        return;
    }
    
    if (this->removeBullet(gid)) {
        return;
    }
}

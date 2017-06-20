//
//  DataManager.cpp
//  zwdz
//
//  Created by zhouzhan on 12/6/17.
//
//

#include "DataManager.h"
#include "MonsterData.h"
#include "BulletData.h"

static DataManager* sharedInstance = nullptr;

DataManager::DataManager()
{
    
}

DataManager::~DataManager()
{
    this->removeAllBattleUnitData();
}

DataManager* DataManager::getInstance()
{
    if (sharedInstance == nullptr) {
        sharedInstance = new DataManager();
    }
    return sharedInstance;
}

void DataManager::destroyInstance()
{
    delete sharedInstance;
    sharedInstance = nullptr;
}

UnitBaseData* DataManager::createMonster(int gid, int configId)
{
    MonsterData* monster_data = new MonsterData();
    monster_data->init(gid, configId);
    
    m_battleUnitDatas.insert(std::pair<int, UnitBaseData*>(gid, monster_data));
    
    return monster_data;
}

UnitBaseData* DataManager::createFriend(int gid, int configId)
{
    MonsterData* monster_data = new MonsterData();
    monster_data->init(gid, configId);
    
    m_battleUnitDatas.insert(std::pair<int, UnitBaseData*>(gid, monster_data));
    
    return  monster_data;
}

UnitBaseData* DataManager::createBullet(int  gid, int configId)
{
    BulletData* bullet_data = new BulletData();
    bullet_data->init(gid, configId);
    
    m_bulletUnitDatas.insert(std::pair<int, UnitBaseData*>(gid, bullet_data));
    
    return bullet_data;
}

UnitBaseData* DataManager::getBulletUnitData(int gid)
{
    UnitBaseData* ret = nullptr;
    ButtleUnitDatas::iterator ite = m_bulletUnitDatas.find(gid);
    if (ite != m_bulletUnitDatas.end()) {
        ret = ite->second;
    }
    return ret;
}

void DataManager::removeButtleData(int gid)
{
    ButtleUnitDatas::iterator ite = m_bulletUnitDatas.find(gid);
    if (ite != m_bulletUnitDatas.end()) {
        CC_SAFE_DELETE(ite->second);
        m_bulletUnitDatas.erase(ite);
    }
}

UnitBaseData* DataManager::getBattleUnitData(int gid)
{
    UnitBaseData* ret = nullptr;
    BattleUnitDatas::iterator ite = m_battleUnitDatas.find(gid);
    if (ite != m_battleUnitDatas.end()) {
        ret = ite->second;
    }
    return ret;
}

void DataManager::removeBattleUnitData(int gid)
{
    BattleUnitDatas::iterator ite = m_battleUnitDatas.find(gid);
    if (ite != m_battleUnitDatas.end()) {
        CC_SAFE_DELETE(ite->second);
        m_battleUnitDatas.erase(ite);
    }
    
    ButtleUnitDatas::iterator ite1 = m_bulletUnitDatas.find(gid);
    if (ite1 != m_bulletUnitDatas.end()) {
        CC_SAFE_DELETE(ite1->second);
        m_bulletUnitDatas.erase(ite1);
    }
    
}

void DataManager::removeAllBattleUnitData()
{
    BattleUnitDatas::iterator ite = m_battleUnitDatas.begin();
    for (; ite != m_battleUnitDatas.end();)
    {
        CC_SAFE_DELETE(ite->second);
        m_battleUnitDatas.erase(ite++);
    }
    
}

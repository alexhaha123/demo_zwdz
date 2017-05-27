#include "GIDFactory.h"

static GIDFactory* m_sharedInstance = nullptr;

GIDFactory::GIDFactory():m_nextGid(0){
    
}

GIDFactory::~GIDFactory(){
    
}

GIDFactory* GIDFactory::getInstance(){
    if (m_sharedInstance == nullptr) {
        m_sharedInstance = new GIDFactory();
        m_sharedInstance->init();
    }
    return m_sharedInstance;
}

bool  GIDFactory::init(){
    m_nextGid = 1000;
    return true;
}

unsigned int GIDFactory::getNextGid(){
    m_nextGid += 1;
    return m_nextGid;
}

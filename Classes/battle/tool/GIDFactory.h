#ifndef __GIDFACTORY_H_
#define __GIDFACTORY_H_

class GIDFactory {
public:
    static GIDFactory* getInstance();
    bool init();
    unsigned int getNextGid();
    ~GIDFactory();
    
    
private:
    GIDFactory();
    
private:
    unsigned int m_nextGid;
};

#endif

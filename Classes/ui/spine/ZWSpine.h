//
//  Header.h
//  zwdz
//
//  Created by zhouzhan on 17/6/1.
//
//

#ifndef ZWSPINE_H
#define ZWSPINE_H

#include <spine/spine-cocos2dx.h>

class ZWSpine : public spine::SkeletonAnimation{
public:
    ZWSpine(const std::string& skeletonDataFile, const std::string& atlasFile, float scale);
    ~ZWSpine();
    
    static ZWSpine* create(const std::string& skeletondata, const std::string& atlasname, float scale = 1);
    
    bool init();
    
    void play(const std::string& actionname, bool isLoop);
    
    inline void setFinishEventListener(const spine::CompleteListener& completelistener){this->m_completelistener = completelistener;}
    
    void pause();
    
    void resume();
    
private:
    spine::CompleteListener m_completelistener;
};

#endif /* Header_h */

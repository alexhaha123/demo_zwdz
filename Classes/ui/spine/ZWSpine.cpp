#include "ZWSpine.h"

ZWSpine::ZWSpine(const std::string& skeletonDataFile, const std::string& atlasFile, float scale)
:spine::SkeletonAnimation(skeletonDataFile, atlasFile, scale){
    
}

ZWSpine* ZWSpine::create(const std::string& filename, const std::string& atlasname, float scale){
    ZWSpine* node = new ZWSpine(filename, atlasname, scale);
    node->init();
    node->autorelease();
    return node;
}

bool ZWSpine::init(){
    this->setCompleteListener([this](int trackIndex, int loopCount) {
        if (this->m_completelistener) {
            this->m_completelistener(trackIndex, loopCount);
        }
    });
    
    return true;
}

void  ZWSpine::play(const std::string& actionname, bool isLoop){
    this->setAnimation(0, actionname, isLoop);
}

void  ZWSpine::pause(){
    spine::SkeletonAnimation::pause();
}

void  ZWSpine::resume(){
    spine::SkeletonAnimation::resume();
}

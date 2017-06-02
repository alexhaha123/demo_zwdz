#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "UIImageView.h"
#include <spine/spine-cocos2dx.h>
#include <map>

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void menuCloseCallback1(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    HelloWorld();
private:
    std::map<int, std::string> spine_act_map;
    spine::SkeletonAnimation* m_spine;
    int ratation_y;
};

#endif // __HELLOWORLD_SCENE_H__

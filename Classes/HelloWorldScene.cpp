#include "HelloWorldScene.h"
#include "GIDFactory.h"
#include "UIloader.h"
#include <string>
#include "BattleMap.h"

USING_NS_CC;

HelloWorld::HelloWorld():ratation_y(0){
    spine_act_map = {{1,"death"}, {2,"hit"},{3,"idle"},{4,"jump"},{5,"run"},{6,"shoot"},{7,"test"},{8,"walk"}};
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size winSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    auto closeItem1 = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback1, this));
    
    closeItem1->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width * 1.5,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem,closeItem1,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    unsigned int gid = GIDFactory::getInstance()->getNextGid();

    char s;
    sprintf(&s, "%d", gid);
    const std::string str = &s;
    
    auto label = Label::createWithTTF(str, "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    BattleMap* map =  BattleMap::create();
    map->initSceneId(1);
    this->addChild(map);
    
    return true;
}

void HelloWorld::menuCloseCallback1(cocos2d::Ref* pSender){

}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

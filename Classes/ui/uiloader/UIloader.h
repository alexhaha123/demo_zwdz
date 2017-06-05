#ifndef __UILOADER_CPP__
#define __UILOADER_CPP__

#include "cocostudio/cocostudio.h"
#include "ui/UIHelper.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

class UIloader : public ui::Helper{
public:
    static Node* load(const std::string& filename);
};




#endif

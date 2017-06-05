#include "UIloader.h"

Node* UIloader::load(const std::string& filename){
    if (filename.empty()) {
        return nullptr;
    }
    return CSLoader::getInstance()->createNode(filename);
}

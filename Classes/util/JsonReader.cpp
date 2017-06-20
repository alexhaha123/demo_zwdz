//
//  JsonReader.cpp
//  zwdz
//
//  Created by zhouzhan on 10/6/17.
//
//

#include "JsonReader.h"
JsonReader* JsonReader::sharedInstance = nullptr;

JsonReader* JsonReader::getInstance()
{
    if (sharedInstance == nullptr) {
        sharedInstance = new JsonReader();
    }
    return  sharedInstance;
}

JsonReader::~JsonReader()
{
    for (Map_confData::iterator ite = m_confMap.begin(); ite != m_confMap.end(); ++ite) {
        delete ite->second;
    }
}

JsonReader* JsonReader::destroyInstance()
{
    if (sharedInstance) {
        delete sharedInstance;
        sharedInstance = nullptr;
    }
}

rapidjson::Document* JsonReader::loadJsonFile(const std::string& fileName)
{
    ssize_t size;
    
    unsigned char* fbuffer = cocos2d::FileUtils::getInstance()->getFileData(fileName, "r", &size);
    
    std::string load_str((const char*) fbuffer, size);
    
    delete fbuffer;
    
    rapidjson::Document* _doc = new rapidjson::Document();

    _doc->Parse<0>(load_str.c_str());
    
    return _doc;
}

const std::string JsonReader::getStringByKey(const std::string& filename, const std::string& key)
{
    bool isLoaded = isInMap(filename);
    if (isLoaded)
    {
        Map_confData::iterator ite = m_confMap.find(filename);
        if (ite->second->HasMember(key.c_str())) {
            return std::string((*ite->second)[key.c_str()].GetString());
        }
    }else
    {
        //加载文件
        rapidjson::Document* doc = loadJsonFile(filename);
        m_confMap.insert(std::pair<std::string, rapidjson::Document*>(filename, doc));
        if (doc->HasMember(key.c_str())) {
            return std::string((*doc)[key.c_str()].GetString());

        }

    }
    return "";
}

int JsonReader::getIntByKey(const std::string& filename, const std::string& key) 
{
    bool isLoaded = isInMap(filename);
    if (isLoaded)
    {
        Map_confData::iterator ite = m_confMap.find(filename);
        if (ite->second->HasMember(key.c_str())) {
            return (*ite->second)[key.c_str()].GetInt();
        }
    }else
    {
        //加载文件
        rapidjson::Document* doc = loadJsonFile(filename);
        m_confMap.insert(std::pair<std::string, rapidjson::Document*>(filename, doc));
        if (doc->HasMember(key.c_str())) {
            return (*doc)[key.c_str()].GetInt();
        }
        
    }
}

bool JsonReader::isInMap(const std::string& filename)
{
    bool ret = false;
    Map_confData::iterator ite = m_confMap.find(filename);
    if (ite != m_confMap.end()) {
        ret = true;
    }
    return  ret;
}

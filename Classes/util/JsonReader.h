//
//  JsonReader.h
//  zwdz
//
//  Created by zhouzhan on 10/6/17.
//
//

#ifndef JsonReader_h
#define JsonReader_h

#include <json/rapidjson.h>
#include <json/document.h>

typedef std::map<std::string, rapidjson::Document*> Map_confData;

class JsonReader {
public:
    static JsonReader* getInstance();
    static JsonReader* destroyInstance();
    
    ~JsonReader();
    
    rapidjson::Document* loadJsonFile(const std::string& fileName);
    
    const std::string getStringByKey(const std::string& filename, const std::string& key);
    
    int getIntByKey(const std::string& filename, const std::string& key);
    
    bool isInMap(const std::string& filename);
private:
    static JsonReader* sharedInstance;
    Map_confData m_confMap;

};

#endif /* JsonReader_h */

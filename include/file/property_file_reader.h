#ifndef PROPERTY_FILE_READER_H
#define PROPERTY_FILE_READER_H

#include <string>
#include <vector>
#include <memory>
#include <map>

class PropertyFileReader{
    public:
        //returns map <key, value>
        //expected line format is key=value or key:value
        std::shared_ptr<std::vector<std::vector<std::string>>> MapFile(const std::string path);
        
        //returns map <key, value>
        //expected line format is key=value or key:value
        //only returns properties where the keys match what was provided
        //default value if the key is not found is nullptr
        std::shared_ptr<std::map<std::string, std::string>> MapFile(
            const std::string path,
            const std::vector<std::string> keys);
};

#endif
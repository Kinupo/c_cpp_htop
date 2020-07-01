#include "file/property_file_reader.h"

//returns map <key, value>
//expected line format is key=value or key:value
std::shared_ptr<std::vector<std::vector<std::string>>> PropertyFileReader::MapFile(const std::string path){
    return nullptr;
};

//returns map <key, value>
//expected line format is key=value or key:value
//only returns properties where the keys match what was provided
//default value if the key is not found is nullptr
std::shared_ptr<std::map<std::string, std::string>> PropertyFileReader::MapFile(
    const std::string path,
    const std::vector<std::string> keys){
        return nullptr;
};
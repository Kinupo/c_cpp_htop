#ifndef DELIMITED_FILE_READER_H
#define DELIMITED_FILE_READER_H

#include <string>
#include <vector>
#include <memory>
#include <map>

class DelimitedFileReader{
    public:
        //returns vector with each elment a row, 
        //and each row contains the columns split by the delimter 
        std::shared_ptr<std::vector<std::vector<std::string>>> MapFile(
            const std::string path,
            const std::string delmiter);
        
        //returns map <key, mapped row>
        //only returns rows that start with one of the provided keys
        //default value if the key is not found is nullptr
        std::shared_ptr<std::map<std::string, std::vector<std::string>>> MapFile(
            const std::string path,
            const std::string delmiter,
            const std::vector<std::string> keys);
};

#endif
#include "file/delimited_file_reader.h"



//returns vector with each elment a row, 
//and each row contains the columns split by the delimter 
std::shared_ptr<std::vector<std::vector<std::string>>> DelimitedFileReader::MapFile(
    const std::string path,
    const std::string delmiter){
        return nullptr;
};

//returns map <key, mapped row>
//only returns rows that start with one of the provided keys
//default value if the key is not found is nullptr
std::shared_ptr<std::map<std::string, std::vector<std::string>>> DelimitedFileReader::MapFile(
    const std::string path,
    const std::string delmiter,
    const std::vector<std::string> keys){
        return nullptr;
    };

//returns map <key, mapped row>
//key column is used to search a column other than the first column - this is zero indexed
//default value if the key is not found is nullptr
std::shared_ptr<std::map<std::string, std::vector<std::string>>> DelimitedFileReader::MapFile(
    const std::string path,
    const std::string delmiter,
    const std::vector<std::string> keys,
    const int key_column){
        return nullptr;
    };
#include "system/user/user_repository.h"

std::shared_ptr<User> UserRepository::FindUser(const int id){

    std::string user_name = "Not Found";

    auto user_id_key = ":" + std::to_string(id) + ":";
    std::vector<std::string> keys = {user_id_key};

    auto unparsed_user = FileReader::ReadLines(kUsersPath, keys);
    auto parsed_user_name = DelimitedParser::ParseLine((*unparsed_user)[user_id_key], ':');
    if(parsed_user_name->size() > 0)
        user_name = parsed_user_name->at(0);
    
    return std::make_shared<User>(id, user_name);
};
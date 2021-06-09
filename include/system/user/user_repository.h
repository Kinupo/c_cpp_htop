#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include <memory>

#include "system/user/user.h"
#include "file_reader/file_reader.h"
#include "parser/delimited_parser.h"

class UserRepository{
    private:
        const std::string kUsersPath = "/etc/passwd";
    public:
        std::shared_ptr<User> FindUser(const int id);
};

#endif
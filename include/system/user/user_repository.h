#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include "system/user/user.h"

#include <memory>

class UserRepository{
    public:
        std::shared_ptr<User> FindUser(const int id);
};

#endif
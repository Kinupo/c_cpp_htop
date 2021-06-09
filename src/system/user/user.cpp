#include "system/user/user.h"

User::User(const int id, const std::string name)
    : id_(id), name_(name){};

int User::Id(){
    return id_;
};

const std::string User::Name(){
    return name_;
};
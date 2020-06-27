#include "system/user/user.h"

User::User(const int id_, const std::string name_)
    : id(id_), name(name_){};
const int User::Id(){
    return id;
};
const std::string User::Name(){
    return name;
};
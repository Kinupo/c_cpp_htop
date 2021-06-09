#ifndef USER_H
#define USER_H

#include <string>

class User{
    private:
        const int id_;
        const std::string name_;
    public:
        User(const int id, const std::string name);
        int Id();
        const std::string Name();
};

#endif
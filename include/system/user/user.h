#ifndef USER_H
#define USER_H

#include <string>

class User{
    private:
        const int id;
        const std::string name;
    public:
        User(const int id, const std::string name);
        const int Id();
        const std::string Name();
};

#endif
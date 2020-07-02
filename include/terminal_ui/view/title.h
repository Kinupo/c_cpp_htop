#ifndef TITLE_H
#define TITLE_H

#include "terminal_ui/position.h"

#include <string>

class Title {
    private:
        const std::string text;
        const Position position;
    public:
        Title(const std::string text, const Position position);
        std::string Text() const;
        Position RelativePosition() const;
};
     
#endif
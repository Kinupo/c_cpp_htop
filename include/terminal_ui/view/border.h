#ifndef BORDER_H
#define BORDER_H

#include "terminal_ui/view/title.h"

class Border{
    private:
        const Title title;
    public:
        Border(const Title title);
        Title TitleElement();
};

#endif
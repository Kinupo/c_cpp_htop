#ifndef ROW_H
#define ROW_H

#include "terminal_ui/element/element.h"

#include <vector>

class Row {
    private:
        const std::vector<Element> elements;
    public:
        Row(const std::vector<Element> elements);
        std::vector<Element> Elements();
};

#endif
#include "terminal_ui/element/row.h"

Row::Row(const std::vector<Element> elements_):elements(elements_){};

std::vector<Element> Row::Elements(){
    return elements;
};
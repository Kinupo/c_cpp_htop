#include "terminal_ui/view/dimension.h"

Dimension::Dimension(const int height_, const int width_): height(height_), width(width_){};

int Dimension::Height() const {return height;};
int Dimension::Width() const {return width;};
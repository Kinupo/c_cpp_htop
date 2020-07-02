#include "terminal_ui/view/title.h"

Title::Title(const std::string text_, const Position position_):text(text_), position(position_) {}

std::string Title::Text() const {return text;}
Position Title::RelativePosition() const {return position;}
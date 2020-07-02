#include "terminal_ui/view/view.h"

View::View(
    const std::string name_, 
    const std::shared_ptr<Border> border_, 
    const std::vector<Row> rows_, 
    const Dimension dimension_,
    const Position position_)
    : name(name_), 
      border(border_), 
      rows(rows_), 
      number_of_border_rows(border_ != nullptr ? 2 : 0), 
      dimension(dimension_),
      position(position_)
    {}

std::string View::Name() const {return name;}
std::shared_ptr<Border> View::BorderElement() const {return border;}

std::unique_ptr<Dimension> View::Dimensions() {
    return std::make_unique<Dimension>(
        dimension.Height() + number_of_border_rows,
        dimension.Width());
}

std::vector<Row> View::Rows() const {return rows;}
Position View::RelativePosition() const {return position;}
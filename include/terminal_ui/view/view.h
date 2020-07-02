#ifndef VIEW_H
#define VIEW_H

#include "terminal_ui/view/border.h"
#include "terminal_ui/element/row.h"
#include "terminal_ui/view/dimension.h"

#include <string>
#include <vector>
#include <memory>

class View {
    private:
        const int number_of_border_rows;
        const std::shared_ptr<Border> border;
        const std::string name;
        const std::vector<Row> rows;
        const Dimension dimension;
        const Position position;
    public:
        View(
            const std::string name, 
            const std::shared_ptr<Border> border, 
            const std::vector<Row> rows, 
            const Dimension dimension,
            const Position position);
        std::string Name() const;
        std::shared_ptr<Border> BorderElement() const;
        std::unique_ptr<Dimension> Dimensions();
        std::vector<Row> Rows() const;
        Position RelativePosition() const;
};

#endif
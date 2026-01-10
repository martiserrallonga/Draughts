#pragma once
#include "Drawable.h"
#include "Entity.h"
#include "Cell.h"

#include <vector>

static constexpr int kCellsPerRow = 8;
static constexpr int kCellNumber = 64;

class Board : public IEntity, public IDrawable {
public:
    Board(Rectangle rect)
        : rectangle(rect)
    {
        float cellWidth = rectangle.width / static_cast<float>(kCellsPerRow);
        float cellHeight = rectangle.height / static_cast<float>(kCellsPerRow);

        for (int index = 0; index < kCellNumber; ++index) {
            const int col = index % kCellsPerRow;
            const int row = index / kCellsPerRow;

            Rectangle cellRect;
            cellRect.x = static_cast<float>(col) * cellWidth + rectangle.x;
            cellRect.y = static_cast<float>(row) * cellHeight + rectangle.y;
            cellRect.width = cellWidth;
            cellRect.height = cellHeight;

            Color color = (col + row) % 2 == 0 ? LIGHTGRAY : DARKBROWN;
            cells.emplace_back(std::make_unique<Cell>(cellRect, color));
        }
    }

    void draw() const override {
        for (const auto& cell : cells)
            cell->draw();
    }
private:
    Rectangle rectangle;
    std::vector<std::unique_ptr<Cell>> cells;
};

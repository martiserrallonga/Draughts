#pragma once
#include "Drawable.h"
#include "Entity.h"
#include "Cell.h"

#include <vector>

static constexpr int kCellsPerRow = 8;
static constexpr int kCellNumber = 64;

class Board : public IEntity, public IDrawable {
public:
    Board(int w, int h)
        : width(static_cast<float>(w))
        , height(static_cast<float>(h))
    {
        float cellWidth = width / static_cast<float>(kCellsPerRow);
        float cellHeight = height / static_cast<float>(kCellsPerRow);

        for (int index = 0; index < kCellNumber; ++index) {
            const int col = index % kCellsPerRow;
            const int row = index / kCellsPerRow;

            Rectangle rect;
            rect.x = static_cast<float>(col) * cellWidth;
            rect.y = static_cast<float>(row) * cellHeight;
            rect.width = cellWidth;
            rect.height = cellHeight;

            Color color = (col + row) % 2 == 0 ? LIGHTGRAY : DARKBROWN;
            cells.emplace_back(std::make_unique<Cell>(rect, color));
        }
    }

    void draw() const override {
        ClearBackground(RAYWHITE);

        for (const auto& cell : cells)
            cell->draw();
    }
private:
    std::vector<std::unique_ptr<Cell>> cells;

    float width;
    float height;
};

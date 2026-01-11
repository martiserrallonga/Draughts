#pragma once
#include "Drawable.h"
#include "Entity.h"

#include <memory>

class Cell : public IEntity, public IDrawable {
public:
    Cell(Rectangle rect, Color color) noexcept
        : rectangle(std::move(rect))
        , color(std::move(color))
    {
    }

    void draw() const noexcept override {
        DrawRectangleRec(rectangle, color);
    }

private:
    Rectangle rectangle;
    Color color;
};


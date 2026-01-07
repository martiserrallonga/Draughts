#pragma once
#include "Drawable.h"
#include "Entity.h"

#include <memory>

class Cell : public IEntity, public IDrawable {
public:
    Cell(Rectangle rect, Color color)
        : rectangle(std::move(rect))
        , color(std::move(color))
    {
    }

    void draw() const override {
        DrawRectangleRec(rectangle, color);
    }

private:
    Rectangle rectangle;
    Color color;
};


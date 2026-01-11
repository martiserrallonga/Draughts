#pragma once
#include "Drawable.h"
#include "Entity.h"
#include "Cell.h"
#include "Window.h"
#include "DrawUtils.h"

#include <vector>


static constexpr int kCellsPerRow = 8;
static constexpr int kCellNumber = 64;
static constexpr float kWindowMargin = 0.1f;

class Board : public IEntity, public IDrawable {
public:
	Board();

	void draw() const override {
		for (const auto& cell : cells)
			cell->draw();

		Draw::RectangleLines(rectangle, DARKBROWN);
	}

private:
	Rectangle rectangle;
	std::vector<std::unique_ptr<Cell>> cells;
};

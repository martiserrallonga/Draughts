#pragma once
#include "Drawable.h"
#include "Entity.h"

#include "raylib.h"
#include <memory>

class Piece;

class Cell : public IEntity, public IDrawable {
public:
	Cell(int index, Rectangle rect, Color color);

	void draw() const override;

	int getIndex() const noexcept;
	void setPiece(Piece* aPiece);

private:
	int index;
	Piece* piece = nullptr;

	Rectangle rectangle;
	Color color;
};


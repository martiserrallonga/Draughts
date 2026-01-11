#include "Cell.h"
#include "Piece.h"

Cell::Cell(int index, Rectangle rect, Color color) noexcept
	: index(index)
	, rectangle(rect)
	, color(color)
{
}

void Cell::draw() const noexcept {
	DrawRectangleRec(rectangle, color);
}

int Cell::getIndex() {
	return index;
}

void Cell::setPiece(Piece* aPiece) {
	piece = aPiece;

	Vector2 cellCenter{
		rectangle.x + rectangle.width / 2.f,
		rectangle.y + rectangle.height / 2.f
	};
	piece->setCell(this, cellCenter);
}

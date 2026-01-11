#include "Cell.h"
#include "Piece.h"

Cell::Cell(int index, Rectangle rect, Color color)
	: index(index)
	, rectangle(rect)
	, color(color)
{
}

void Cell::draw() const {
	DrawRectangleRec(rectangle, color);
}

int Cell::getIndex() const noexcept {
	return index;
}

void Cell::setPiece(Piece* aPiece) {
	piece = aPiece;

	const Vector2 cellCenter{
		rectangle.x + rectangle.width / 2.f,
		rectangle.y + rectangle.height / 2.f
	};
	piece->setCell(this, cellCenter);
}

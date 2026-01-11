#include "Board.h"
#include "Game.h"
#include "Piece.h"

Board::Board() {
	const Window& window = Game::GetWindow();
	rectangle.x = window.width * kWindowMargin / 2.f;
	rectangle.y = window.height * kWindowMargin / 2.f;
	rectangle.width = window.width * (1.f - kWindowMargin);
	rectangle.height = window.height * (1.f - kWindowMargin);

	const float cellWidth = rectangle.width / static_cast<float>(kCellsPerRow);
	const float cellHeight = rectangle.height / static_cast<float>(kCellsPerRow);

	for (int index = 0; index < kCellNumber; ++index) {
		const int col = index % kCellsPerRow;
		const int row = index / kCellsPerRow;

		Rectangle cellRect;
		cellRect.x = static_cast<float>(col) * cellWidth + rectangle.x;
		cellRect.y = static_cast<float>(row) * cellHeight + rectangle.y;
		cellRect.width = cellWidth;
		cellRect.height = cellHeight;

		Color color = (col + row) % 2 == 0 ? LIGHTGRAY : DARKBROWN;
		cells.emplace_back(std::make_unique<Cell>(index, cellRect, color));
	}
}

void Board::addPiece(Piece* piece, int index) {
	cells.at(index)->setPiece(piece);
}

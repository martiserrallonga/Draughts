#include "Cell.h"
#include "Piece.h"
#include "Player.h"

#include "raylib.h"


Piece::Piece(const Player* player)
	: player(player)
	, model(player->clonePieceModel())
{
}

void Piece::draw() const {
	DrawCircleV(position, model.radius, model.colorLight);
	DrawCircleV(position, model.radius * 0.8, model.colorDark);
	DrawCircleV(position, model.radius * 0.6, model.colorLight);
}

void Piece::onClick() {

}

void Piece::onDrag() {

}

int Piece::getIndex() {
	return cell->getIndex();
}

void Piece::setCell(Cell* aCell, Vector2 pos) {
	cell = aCell;
	position = pos;
}

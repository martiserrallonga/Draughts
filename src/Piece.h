#pragma once
#include "Entity.h"
#include "Drawable.h"
#include "InputHandler.h"
#include "PieceModel.h"

class Player;
class Cell;


class Piece : public IEntity, public IDrawable, public IInputHandler {
public:
	Piece(const Player* player);

	void draw() const override;
	void onClick() override;
	void onDrag() override;

	int getIndex();

	void setCell(Cell* aCell, Vector2 pos);

private:
	const Player* player;
	PieceModel model;

	Cell* cell = nullptr;
	Vector2 position{};
};

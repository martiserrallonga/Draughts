#pragma once
#include "Entity.h"
#include "Piece.h"
#include "PieceModel.h"

#include <vector>
#include <memory>

class Player : public IEntity, public IDrawable {
public:	
	void draw() const override {
		for (const auto& piece : pieces)
			piece->draw();
	}

	void addPiece(int index);
	
	void setPieceModel(PieceModel model);
	PieceModel clonePieceModel() const;

private:
	std::vector<std::unique_ptr<Piece>> pieces;
	PieceModel piecesModel;
};

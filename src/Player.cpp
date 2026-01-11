#include "Player.h"
#include "Game.h"

void Player::addPiece(int index) {
	auto piece = std::make_unique<Piece>(this);
	Game::GetBoard()->addPiece(piece.get(), index);
	pieces.push_back(std::move(piece));
}

void Player::setPieceModel(PieceModel model) {
	piecesModel = model;
}

PieceModel Player::clonePieceModel() const {
	return piecesModel;
}

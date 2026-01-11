#pragma once
#include "Board.h"
#include "Player.h"
#include <array>

static std::array<int, 12> kPositionsTop = { 1, 3, 5, 7, 8, 10, 12, 14, 17, 19, 21, 23 };
static std::array<int, 12> kPositionsBottom = { 62, 60, 58, 56, 55, 53, 51, 49, 46, 44, 42, 40 };

class GameState {
public:
	GameState() = default;
	GameState(Board* board, Player* current, Player* next)
		: board(board)
		, currentPlayer(current)
		, nextPlayer(next)
	{
	}

	void setStartState() {
		for (auto index : kPositionsTop) {
			currentPlayer->addPiece(index);
		}

		for (auto index : kPositionsBottom) {
			nextPlayer->addPiece(index);
		}
	}

private:
	Board* board = nullptr;
	Player* currentPlayer = nullptr;
	Player* nextPlayer = nullptr;
};

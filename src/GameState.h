#pragma once
#include "Board.h"
#include "Player.h"

#include <memory>

class GameState {
public:
	GameState(Board* board, Player* current, Player* next)
		: board(board)
		, currentPlayer(current)
		, nextPlayer(next)
	{
	}

private:
	Board* board;
	Player* currentPlayer;
	Player* nextPlayer;
};

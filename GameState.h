#pragma once
#include "Board.h"
#include "Player.h"

#include <memory>

class GameState {
public:
	GameState(Board* board)
		: board(board)
	{
	}

	void switchPlayer() {
		currentPlayer.swap(nextPlayer);
	}

private:
	Board* board;
	std::shared_ptr<Player> currentPlayer;
	std::shared_ptr<Player> nextPlayer;
};

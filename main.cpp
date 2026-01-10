#include <iostream>
#include <vector>

std::vector<char> board{
	'.','x','.','x','.','x','.','x',
	'x','.','x','.','x','.','x','.',
	'.','x','.','x','.','x','.','x',
	'.','.','.','.','.','.','.','.',
	'.','.','.','.','.','.','.','.',
	'o','.','o','.','o','.','o','.',
	'.','o','.','o','.','o','.','o',
	'o','.','o','.','o','.','o','.',
};

char currentPlayer;
char player1 = 'x';
char player2 = 'o';

struct Coords {
	int x;
	int y;
};

Coords indexToCoords(int index) {
	return { index % 8, index / 8 };
}

int coordsToIndex(Coords coords) {
	return coords.x + coords.y * 8;
}

void printBoard() {
	for (int i = 0; i < board.size(); ++i) {
		if (i % 8 == 0)
			std::cout << '\n';

		std::cout << ' ' << board.at(i);
	}
	std::cout << "\n";
}

void movePawn(int from, int to) {
	// from == to
	// from == '.'
	// to is ocupied
	// currentPlayer != from
	board.at(to) = board.at(from);
	board.at(from) = '.';
}

bool hasAnyPawn(char player) {
	for (auto cell : board) {
		if (cell == player)
			return true;
	}

	return false;
}

void checkWinCondition() {
	if (!hasAnyPawn('o')) {
		std::cout << "Player 'x' wins" << std::endl;
	}

	if (!hasAnyPawn('x')) {
		std::cout << "Player 'o' wins" << std::endl;
	}
}

void capture(int from, int jump, int to) {
	movePawn(from, jump);
	movePawn(jump, to);
}

void switchPlayer(char player) {
	if (currentPlayer == player)
		std::cout << "ERROR: Current player is already " << player << std::endl;

	currentPlayer = player;
}

void game() {
	printBoard();

	switchPlayer(player2);
	movePawn(coordsToIndex({ 0,5 }), coordsToIndex({ 1,4 }));
	checkWinCondition();
	printBoard();

	switchPlayer(player1);
	movePawn(coordsToIndex({ 3,2 }), coordsToIndex({ 2,3 }));
	checkWinCondition();
	printBoard();

	switchPlayer(player2);
	capture(
		coordsToIndex({ 1,4 }),
		coordsToIndex({ 2,3 }),
		coordsToIndex({ 3,2 }));
	checkWinCondition();
	printBoard();

}

#include "raylib.h"
#include "Scene.h"
#include "Window.h"
#include "GameState.h"

static constexpr const char* kTitle = "Draughts";
static constexpr int kWidth = 640;
static constexpr int kHeight = 640;

int main() {
	Window window(kTitle, kWidth, kHeight);

	auto board = std::make_unique<Board>(window);
	auto player1 = std::make_unique<Player>();
	auto player2 = std::make_unique<Player>();
	GameState gameState(board.get(), player1.get(), player2.get());

	Scene scene;
	scene.add(std::move(board));
	scene.add(std::move(player1));
	scene.add(std::move(player2));

	while (!WindowShouldClose()) {
		scene.draw();
	}
}
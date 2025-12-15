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

void game() {
	printBoard();
	currentPlayer = player2;
	movePawn(coordsToIndex({ 0,5 }), coordsToIndex({ 1,4 }));
	checkWinCondition();

	printBoard();
	currentPlayer = player1;
	movePawn(coordsToIndex({ 3,2 }), coordsToIndex({ 2,3 }));
	checkWinCondition();

	printBoard();
	currentPlayer = player2;
	capture(
		coordsToIndex({ 1,4 }),
		coordsToIndex({ 2,3 }),
		coordsToIndex({ 3,2 }));
	checkWinCondition();

	printBoard();
}

#include "raylib.h"

int main() {
	InitWindow(640, 640, "Draughts");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		int cell = 640 / 8;

		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				bool dark = (x + y) % 2 == 1;
				DrawRectangle(x * cell, y * cell, cell, cell,
					dark ? DARKBROWN : LIGHTGRAY);
			}
		}

		EndDrawing();
	}

	CloseWindow();
}
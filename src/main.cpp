#include "Game.h"

int main() {
	Game& game = Game::Get();
	game.initialize();
	while (game.handleEvents()) {
		game.update();
		game.render();
	}

	return 0;
}
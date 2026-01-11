#pragma once
#include "GameState.h"
#include "Scene.h"
#include "Window.h"

#include "raylib.h"


static constexpr const char* kTitle = "Draughts";
static constexpr int kWidth = 640;
static constexpr int kHeight = 640;

class Game {
public:
	Game() : window(kTitle, kWidth, kHeight) {}

	void initialize() {
		board = std::make_unique<Board>();
		player1 = std::make_unique<Player>();
		player2 = std::make_unique<Player>();
		gameState = GameState(board.get(), player1.get(), player2.get());

		scene.add(board.get());
		scene.add(player1.get());
		scene.add(player2.get());
	}

	bool handleEvents() {
		return !WindowShouldClose();
	}

	void update() {}

	void render() {
		scene.draw();
	}

	static Game& Get() {
		static Game instance = Game();
		return instance;
	}

	static const Window& GetWindow() {
		return Get().window;
	}

private:
	Window window;
	GameState gameState;
	Scene scene;

	std::unique_ptr<Board> board;
	std::unique_ptr<Player> player1;
	std::unique_ptr<Player> player2;
};

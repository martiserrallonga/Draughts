#pragma once
#include "Board.h"
#include "Drawable.h"
#include "Entity.h"
#include "Window.h"
#include "GameState.h"

#include "raylib.h"

#include <memory>
#include <vector>

class Scene : public IDrawable {
public:
	void draw() const override {
		BeginDrawing();
		ClearBackground(SKYBLUE);

		for (const auto& entity : drawables)
			entity->draw();

		EndDrawing();
	}

	void add(IDrawable* drawable) {
		drawables.push_back(drawable);
	}

private:
	std::vector<IDrawable*> drawables;
};


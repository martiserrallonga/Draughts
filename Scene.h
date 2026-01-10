#pragma once
#include "Board.h"
#include "Drawable.h"
#include "Entity.h"
#include "Window.h"
#include "GameState.h"

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

	void add(std::unique_ptr<IDrawable> drawable) {
		drawables.push_back(std::move(drawable));
	}

private:
	std::vector<std::unique_ptr<IDrawable>> drawables;
};


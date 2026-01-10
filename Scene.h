#pragma once
#include "Board.h"
#include "Drawable.h"
#include "Entity.h"
#include "Window.h"

#include <memory>
#include <vector>

static constexpr float kWindowMargin = 0.1f;

class Scene : public IDrawable {
public:
	Scene(const Window& window) {
		Rectangle rect;
		rect.x = window.width * kWindowMargin / 2.f;
		rect.y = window.height * kWindowMargin / 2.f;
		rect.width = window.width * (1.f - kWindowMargin);
		rect.height = window.height * (1.f - kWindowMargin);

		std::unique_ptr<IDrawable> board = std::make_unique<Board>(rect);
		drawables.push_back(std::move(board));
	}

	void draw() const override {
		BeginDrawing();
		ClearBackground(SKYBLUE);

		for (const auto& entity : drawables)
			entity->draw();

		EndDrawing();
	}

private:
	std::vector<std::unique_ptr<IDrawable>> drawables;
};


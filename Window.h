#pragma once
#include "raylib.h"
#include <string>

static constexpr int kTargetFPS = 60;

class Window {
public:
	friend class Board;

	Window(std::string title, int width, int height)
		: width(width)
		, height(height)
	{
		InitWindow(width, height, title.c_str());
		SetTargetFPS(kTargetFPS);
	}

	~Window() {
		CloseWindow();
	}

private:
	std::string title;
	int width;
	int height;
};

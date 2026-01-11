#pragma once
#include "raylib.h"

class PieceModel {
	friend class Piece;

public:
	PieceModel() = default;
	PieceModel(float radius, Color colorLight, Color colorDark)
		: radius(radius)
		, colorLight(colorLight)
		, colorDark(colorDark)
	{
	}

	PieceModel clone() {
		return *this;
	}

private:
	float radius = 0.f;
	Color colorLight = BLANK;
	Color colorDark = BLANK;
};
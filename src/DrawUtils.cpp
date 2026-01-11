#include "DrawUtils.h"

namespace Draw {
	void RectangleLines(const Rectangle& rectangle, Color color) {
		Vector2 bottomLeft{ rectangle.x, rectangle.y };
		Vector2 topLeft{ rectangle.x, rectangle.y + rectangle.height };
		Vector2 topRight{ rectangle.x + rectangle.width, rectangle.y + rectangle.height };
		Vector2 bottomRight{ rectangle.x + rectangle.width, rectangle.y };

		DrawLineV(bottomLeft, topLeft, color);
		DrawLineV(topLeft, topRight, color);
		DrawLineV(topRight, bottomRight, color);
		DrawLineV(bottomRight, bottomLeft, color);
	}
}
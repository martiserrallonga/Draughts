#include "DrawUtils.h"

namespace Draw {
	void RectangleLines(const Rectangle& rectangle, Color color) {
		const Vector2 bottomLeft{ rectangle.x, rectangle.y };
		const Vector2 topLeft{ rectangle.x, rectangle.y + rectangle.height };
		const Vector2 topRight{ rectangle.x + rectangle.width, rectangle.y + rectangle.height };
		const Vector2 bottomRight{ rectangle.x + rectangle.width, rectangle.y };

		DrawLineV(bottomLeft, topLeft, color);
		DrawLineV(topLeft, topRight, color);
		DrawLineV(topRight, bottomRight, color);
		DrawLineV(bottomRight, bottomLeft, color);
	}
}
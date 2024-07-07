#include "raylib.h"

void DrawNumberedRectangles(char *letter, Rectangle rectangle, int offset, int fontSize, Color rectangleColor, Color textColor);

int main(void) {
	Color background = {0x11, 0x15, 0x1c, 0xff};
	Color foreground = {0x21, 0x2d, 0x40, 0xff};
	Color text = {0x36, 0x41, 0x56, 0xff};
	InitWindow(800, 800, "raylib test");

	SetTargetFPS(144);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(background);
		Rectangle gridSquare = {80, 80, 64, 64};
		for (int i = 0; i < 10; i++) {
			int offset = i * 64;
			char letter = i + '0';
			DrawNumberedRectangles(&letter, gridSquare, offset, 24, foreground, text);
		}
		EndDrawing();
	}
}

void DrawNumberedRectangles(char *letter, Rectangle rectangle, int offset, int fontSize, Color rectangleColor, Color textColor) {
	int boxCenter = ((rectangle.width - fontSize) / 2);
	int textCenter = (offset + boxCenter );

	DrawRectangleLines(rectangle.x + offset, rectangle.y,
	rectangle.width, rectangle.height, rectangleColor);

	DrawText(letter, rectangle.x + textCenter, rectangle.y + boxCenter,
	fontSize, textColor);
}

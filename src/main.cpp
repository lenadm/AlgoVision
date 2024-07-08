#include "raylib.h"

void DrawNumberedRectangles(char *letter, Rectangle rectangle, int offset, int fontSize);
void DrawInit(void);

const Color background = {0x11, 0x15, 0x1c, 0xff};
const Color foreground = {0x21, 0x2d, 0x40, 0xff};
const Color accents = {0x36, 0x41, 0x56, 0xff};
const Color selectedForeground = {0x91, 0x20, 0x20, 0xff};
const Color selectedaccents = {0xba, 0x18, 0x18, 0xff};

int main(void) {
	InitWindow(800, 800, "raylib test");

	SetTargetFPS(144);

	while (!WindowShouldClose()) {
		BeginDrawing();
		DrawInit();
		EndDrawing();
	}
}

void DrawInit(void) {
	ClearBackground(background);
	Rectangle gridSquare = {80, 80, 64, 64};
	for (int i = 0; i < 10; i++) {
		int offset = i * 64;
		char letter = i + '0';
		DrawNumberedRectangles(&letter, gridSquare, offset, 24);
	}
}

void DrawNumberedRectangles(char *letter, Rectangle rectangle, int offset, int fontSize) {
	int boxCenter = ((rectangle.width - fontSize) / 2);
	int textCenter = (offset + boxCenter );

	DrawRectangle(rectangle.x + offset, rectangle.y,
	rectangle.width, rectangle.height, foreground);

	DrawText(letter, rectangle.x + textCenter, rectangle.y + boxCenter,
	fontSize, accents);

	DrawRectangleLines(rectangle.x + offset, rectangle.y,
	rectangle.width, rectangle.height, accents);
}

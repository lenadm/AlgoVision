#include <string>
#include "raylib.h"

int main(void) {
	Color background = {0x11, 0x15, 0x1c, 0xff};
	Color foreground = {0x21, 0x2d, 0x40, 0xff};
	Color accents = {0x36, 0x41, 0x56, 0xff};
	InitWindow(800, 800, "raylib test");

	SetTargetFPS(144);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(background);
		Rectangle grid = {80, 80, 64, 64};
		for (int i = 0; i < 10; i++) {
			int offset = i * 64;
			DrawRectangleLines(grid.x + offset, grid.y,
			grid.width, grid.height, foreground);
			char letter[] = {char(i + '0')};
			DrawText(letter, grid.x + offset + 20, grid.y + 20,
			24, accents);
		}
		EndDrawing();
	}
}

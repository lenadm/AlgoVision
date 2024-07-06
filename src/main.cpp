#include "raylib.h"

int main(void) {
	InitWindow(800, 800, "raylib test");

	SetTargetFPS(144);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLUE);
		Rectangle grid = {80, 80, 64, 64};
		for (int i = 0; i < 10; i++) {
			int offset = i * 64;
			DrawRectangleLines(grid.x + offset, grid.y,
			grid.width, grid.height, WHITE);
		}
		EndDrawing();
	}
}

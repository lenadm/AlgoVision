#include <raylib.h>

namespace Scene {
	void mainMenu() {
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground({0x00, 0x00, 0x00, 0xff});
			DrawRectangle(10, 10, 126, 78, {0x21, 0x2d, 0x40, 0xff});
			DrawRectangleLines(10, 10, 126, 78, {0xff, 0xff, 0xff, 0xff});
			DrawText("bubblesort", 15, 29, 20, {0xff, 0xff, 0xff, 0xff});
			EndDrawing();
		}
	}
}

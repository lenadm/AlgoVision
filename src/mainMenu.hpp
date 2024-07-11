#include <raylib.h>
#include "./colors.hpp"

extern const Color colors::background;
extern const Color colors::foreground;
extern const Color colors::accents;

namespace Scene {
	void mainMenu() {
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(colors::background);
			DrawRectangle(10, 10, 126, 78, colors::foreground);
			DrawRectangleLines(10, 10, 126, 78, colors::accents);
			DrawText("bubblesort", 15, 29, 20, colors::accents);
			EndDrawing();
		}
	}
}

#include <raylib.h>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include "./colors.hpp"

extern const Color colors::background;
extern const Color colors::foreground;
extern const Color colors::accents;

std::vector<std::string> scenes = {"BubbleSort", "MergeSort"};

namespace Scene {
	void mainMenu() {
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(colors::background);
			for (int i = 0; i < scenes.size(); i++) {
				int lines = floor(i / 10);
				int yPos = 10 + (lines * 78);
				int xPos = (10 + ((i * 126)) - (lines * 126));
				const char *string = scenes[i].c_str();

				DrawRectangle(xPos, yPos, 126, 78, colors::foreground);
				DrawRectangleLines(xPos, yPos, 126, 78, colors::accents);
				DrawText(string, xPos + 5, yPos + 20, 20, colors::accents);
			}
			EndDrawing();
		}
	}
}

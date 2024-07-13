#include <raylib.h>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include "../colors/colors.hpp"

extern const Color colors::background;
extern const Color colors::foreground;
extern const Color colors::accents;


void CreateButton(std::vector<std::string> scenes, std::vector<Rectangle> buttons) {
	for (int i = 0; i < scenes.size(); i++) {
		int lines = floor(i / 10);
		int yPos = 10 + (lines * 78);
		int xPos = (10 + ((i * 126)) - (lines * 126));
		buttons[i] = {(float)xPos, (float)yPos, 126, 78};
		const char *string = scenes[i].c_str();

		DrawRectangle(xPos, yPos, 126, 78, colors::foreground);
		DrawRectangleLines(xPos, yPos, 126, 78, colors::accents);
		DrawText(string, xPos + 5, yPos + 20, 20, colors::accents);
	}
}

namespace Scene {
	void mainMenu() {
		std::vector<std::string> scenes = {"BubbleSort", "MergeSort"};
		std::vector<Rectangle> buttons;

		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(colors::background);
			CreateButton(scenes, buttons);
			EndDrawing();
		}
	}
}

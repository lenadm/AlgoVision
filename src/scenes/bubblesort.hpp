#include <raylib.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <thread>
#include "../colors/colors.hpp"

extern const Color colors::background;
extern const Color colors::foreground;
extern const Color colors::accents;
extern const Color colors::selectedForeground;

namespace {
	static void DrawNumberedRectangles(Rectangle gridSquare, char *letter, int offset, Color primary, Color secondary) {
		int boxCenter = ((gridSquare.width - 24) / 2);
		int textCenter = (gridSquare.x + offset + boxCenter);

		ClearBackground(colors::background);

		DrawRectangle(gridSquare.x + offset, gridSquare.y, gridSquare.width, gridSquare.height, primary);

		DrawText(letter, textCenter, gridSquare.y + boxCenter, 24, secondary);

		DrawRectangleLines(gridSquare.x + offset, gridSquare.y, gridSquare.width, gridSquare.height, secondary);
	}

	static void DrawThread(char *numbers, Rectangle gridSquare) {
		for (int first = 0; first < 9; first++) {
			bool isSorted = true;
			for (int second = 0; second < 9 - first; second++) {
				BeginDrawing();
				for (int box = 0; box < 10; box++) {
					int offset = box * 102;
					char letter[2] = {numbers[box], '\0'};
					if (box == second || box == second + 1) {
						DrawNumberedRectangles(gridSquare, letter, offset, colors::selectedForeground, colors::accents);
					} else {
						DrawNumberedRectangles(gridSquare, letter, offset, colors::foreground, colors::accents);
					}
				}
				EndDrawing();

				if (numbers[second] > numbers[second + 1]) {
					isSorted = false;
					char tmp = numbers[second];
					numbers[second] = numbers[second + 1];
					numbers[second + 1] = tmp;
				}
				sleep(1);
			}
			if (isSorted == true) {
				exit(0);
			}
		}
	}
}

namespace Scene {
	void bubbleSort(void) {
		Rectangle gridSquare = {128, 258, 102, 102};
		srand((unsigned) time(NULL));

		char numbers[10];
		for (int i = 0; i < 10; i++) {
			numbers[i] = char('0' + rand() % 10);
		}

		DrawThread(numbers, gridSquare);
		while (!WindowShouldClose()) {
			std::thread draw(DrawThread, numbers, gridSquare);
			draw.join();
		}
	}
}


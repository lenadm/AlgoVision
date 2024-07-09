#include "raylib.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

const Color background = {0x11, 0x15, 0x1c, 0xff};
const Color foreground = {0x21, 0x2d, 0x40, 0xff};
const Color accents = {0xff, 0xff, 0xff, 0xff};
const Color selectedForeground = {0x91, 0x20, 0x20, 0xff};

const int screenHeight = 800;
const int screenWidth = 800;

void DrawNumberedRectangles(Rectangle gridSquare, char *letter, int offset, Color primary, Color secondary);

int main(void) {
	Rectangle gridSquare = {80, 80, 64, 64};
	InitWindow(800, 800, "raylib test");
	SetTargetFPS(144);
	srand((unsigned) time(NULL));

	char numbers[10];
	for (int i = 0; i < 10; i++) {
		numbers[i] = char('0' + rand() % 10);
	}

	while (!WindowShouldClose()) {
		for (int first = 0; first < 9; first++) {
			for (int second = 0; second < 9; second++) {
				if (numbers[second] > numbers[second + 1]) {
					char tmp = numbers[second];
					numbers[second] = numbers[second + 1];
					numbers[second + 1] = tmp;
				}
				BeginDrawing();
				for (int box = 0; box < 10; box++) {
					int offset = box * 64;
					char letter[2] = {numbers[box], '\0'};
					if (box == second || box == second + 1) {
						DrawNumberedRectangles(gridSquare, letter, offset, selectedForeground, accents);
					} else {
						DrawNumberedRectangles(gridSquare, letter, offset, foreground, accents);
					}
				}
				EndDrawing();
				sleep(1);
			}
		}
	}
}

void DrawNumberedRectangles(Rectangle gridSquare, char *letter, int offset, Color primary, Color secondary) {
	int boxCenter = ((gridSquare.width - 24) / 2);
	int textCenter = (gridSquare.x + offset + boxCenter);

	ClearBackground(background);

	DrawRectangle(gridSquare.x + offset, gridSquare.y, gridSquare.width, gridSquare.height, primary);

	DrawText(letter, textCenter, gridSquare.y + boxCenter, 24, secondary);

	DrawRectangleLines(gridSquare.x + offset, gridSquare.y, gridSquare.width, gridSquare.height, secondary);
}

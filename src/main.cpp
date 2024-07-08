#include "raylib.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

const Color background = {0x11, 0x15, 0x1c, 0xff};
const Color foreground = {0x21, 0x2d, 0x40, 0xff};
const Color accents = {0x36, 0x41, 0x56, 0xff};
const Color selectedForeground = {0x91, 0x20, 0x20, 0xff};
const Color selectedAccents = {0xba, 0x18, 0x18, 0xff};

void DrawNumberedRectangles(char *letter, Rectangle rectangle, int offset, int fontSize, Color foreground, Color accents);
void DrawInit(int *numbers);

int main(void) {
	InitWindow(800, 800, "raylib test");
	SetTargetFPS(144);
	srand((unsigned) time(NULL));

	int numbers[10];
	for (int i = 0; i < 10; i++) {
		numbers[i] = rand() % 10;
	}

	DrawInit(numbers);
	while (!WindowShouldClose()) {
		DrawInit(numbers);
		sleep(1);
	}
}

void DrawNumberedRectangles(char *letter, Rectangle rectangle, int offset, int fontSize, Color foreground, Color accents) {
	int boxCenter = ((rectangle.width - fontSize) / 2);
	int textCenter = (offset + boxCenter );

	DrawRectangle(rectangle.x + offset, rectangle.y,
	rectangle.width, rectangle.height, foreground);

	DrawText(letter, rectangle.x + textCenter, rectangle.y + boxCenter,
	fontSize, accents);

	DrawRectangleLines(rectangle.x + offset, rectangle.y,
	rectangle.width, rectangle.height, accents);
}

void DrawInit(int *numbers) {
	BeginDrawing();
	ClearBackground(background);
	Rectangle gridSquare = {80, 80, 64, 64};
	for (int i = 0; i < 10; i++) {
		int offset = i * 64;
		char letter = numbers[i] + '0';
		DrawNumberedRectangles(&letter, gridSquare, offset, 24, foreground, accents);
	}
	EndDrawing();
}

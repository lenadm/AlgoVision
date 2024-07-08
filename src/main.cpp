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

const int screenHeight = 800;
const int screenWidth = 800;

int main(void) {
	Rectangle gridSquare = {80, 80, 64, 64};
	InitWindow(800, 800, "raylib test");
	RenderTexture2D base = LoadRenderTexture(640, 64);
	SetTargetFPS(144);
	srand((unsigned) time(NULL));

	char numbers[10];
	for (int i = 0; i < 10; i++) {
		numbers[i] = char('0' + rand() % 10);
	}

	BeginTextureMode(base);
	ClearBackground(background);
	for (int i = 0; i < 10; i++) {
		int offset = i * 64;
		char letter[2] = {numbers[i], '\0'};
		int boxCenter = ((gridSquare.width - 24) / 2);
		int textCenter = (offset + boxCenter );

		DrawRectangle(0 + offset, 0, gridSquare.width, gridSquare.height, foreground);

		DrawText(letter, textCenter, 20, 24, accents);

		DrawRectangleLines(0 + offset, 0, gridSquare.width, gridSquare.height, accents);
	}
	EndTextureMode();

	while (!WindowShouldClose()) {
		BeginDrawing();
		DrawTextureRec(base.texture, (Rectangle) {0, 0, (float)base.texture.width, (float)-base.texture.height}, (Vector2) {80, 80}, WHITE);
		EndDrawing();
	}
}


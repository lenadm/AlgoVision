#include "raylib.h"
#include "./sort/bubblesort.hpp"

int main(void) {
	InitWindow(1280, 720, "AlgoVision");
	SetTargetFPS(60);

	Scene::bubbleSort();
	return 0;
}

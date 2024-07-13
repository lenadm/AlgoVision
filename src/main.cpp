#include "raylib.h"
#include "./scenes/bubblesort.hpp"
#include "./scenes/mergeSort.hpp"
#include "./scenes/mainMenu.hpp"

enum Scenes {
		 main_Menu, bubble_Sort, merge_Sort
};

int main(void) {
	Scenes currentScene = main_Menu;
	InitWindow(1280, 720, "AlgoVision");
	SetTargetFPS(60);
	
	Scene::mergeSort();
	return 0;
}

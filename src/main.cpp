#include "raylib.h"
#include "./sort/bubblesort.hpp"
#include "./mainMenu.hpp"

enum Scenes {
		 main_Menu, bubble_Sort
};

int main(void) {
	Scenes currentScene = main_Menu;
	InitWindow(1280, 720, "AlgoVision");
	SetTargetFPS(60);
	
	Scene::mainMenu();
	return 0;
}

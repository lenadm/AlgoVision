cmake_minimum_required(VERSION 3.10.0)
project(algoVision)

include(FetchContent)

set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
	raylib
	URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
	FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

set(CMAKE_CXX_FLAGS "-g")

set(SOURCE_FILES
	./src/main.cpp ./src/scenes/mainMenu.hpp ./src/colors/colors.cpp
	./src/colors/colors.hpp ./src/scenes/bubblesort.hpp ./src/scenes/mergeSort.hpp

)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib)

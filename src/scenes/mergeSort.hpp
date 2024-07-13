#include <raylib.h>
#include <cstdlib>
#include "../colors/colors.hpp"
#include <iostream>

namespace {
	void merge(char *array, int begin, int mid, int end) {
		int subArrayOne = mid - begin + 1;
		int subArrayTwo = end - mid;

		char leftArray[subArrayOne];
		char rightArray[subArrayTwo];

		for (int i = 0; i < subArrayOne; i++) {
			leftArray[i] = array[begin + i];
		}

		for (int i = 0; i < subArrayTwo; i++) {
			rightArray[i] = array[mid + 1 + i];
		}

		int leftPointer = 0;
		int rightPointer = 0;
		int mergedPointer = begin;

		while (leftPointer < subArrayOne && rightPointer < subArrayTwo) {
			if (leftArray[leftPointer] <= rightArray[rightPointer]) {
				array[mergedPointer] = leftArray[leftPointer];
				leftPointer++;
			} else {
				array[mergedPointer] = rightArray[rightPointer];
				rightPointer++;
			}
			mergedPointer++;
		}
		
		while (leftPointer < subArrayOne) {
			array[mergedPointer] = leftArray[leftPointer];
			leftPointer++;
			mergedPointer++;
		}
		
		while (rightPointer < subArrayTwo) {
			array[mergedPointer] = rightArray[rightPointer];
			rightPointer++;
			mergedPointer++;
		}
	}
		
	void partition(char *array, int begin, int end) {
		if (begin >= end) {
			return;
		}

		int mid = begin + (end - begin) / 2;
		partition(array, begin, mid);
		partition(array, mid + 1, end);
		merge(array, begin, mid, end);
	}
}

namespace Scene {
	void mergeSort() {
		Rectangle gridSquare = {10, 20, 126, 80};
		srand((unsigned) time(NULL));

		char numbers[8];
		for (int i = 0; i < 8; i++) {
			numbers[i] = char('0' + rand() % 10);
		}

		partition(numbers, 0, 7);
	}
}

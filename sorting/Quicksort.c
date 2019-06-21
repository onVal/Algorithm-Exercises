#include <stdio.h>
#include "utils.h"

#define LENGTH 8

void quicksort(int *array, int low, int high);
int partition(int *array, int low, int high);

int main() {
	int array[LENGTH] = {4, 29, 9, 11, 0, 7, 5, 81};
   	
	quicksort(array, 0, LENGTH-1);
	print_array(array, LENGTH);
	return 0;
}

void quicksort(int *array, int low, int high) {
	if (high > low) {
		int p = partition(array, low, high);
		quicksort(array, low, p-1);
		quicksort(array, p+1, high);
	}
}

//last element is pivot
int partition(int *array, int low, int high) {
	int pivot = array[high];

	int i = low;
	int j;

	for (j = low; j < high; j++) {
		if (array[j] < pivot) {
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return i;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define LENGTH 9

void merge_sort(int *array, int start, int end);
void merge(int *array, int start, int mid, int end);

int main() {
    int array[LENGTH] = {3, 8, 5, 1, 8, 9, 2, 11, -3};
    merge_sort(array, 0, LENGTH-1);
    print_array(array, LENGTH);

	return 0;
}

void merge_sort(int *array, int start, int end) {
	if (end > start) {
		int m = (start + end) / 2;
		merge_sort(array, start, m);
		merge_sort(array, m+1, end);
	
		merge(array, start, m, end);
	}
}

void merge(int *array, int start, int m, int end) {
	int index1 = start;
	int index2 = m + 1;
	int length = end + 1 - start;

	int *temp = malloc (length * sizeof(int));
	int i = 0; //temp index

	while(index1 <= m && index2 <= end) {
		if (array[index1] < array[index2])
			temp[i++] = array[index1++];
		else 
			temp[i++] = array[index2++];
	}

	while (index1 <= m)
		temp[i++] = array[index1++];

	while (index2 <= end)
		temp[i++] = array[index2++];

	memcpy (array+start, temp, length*sizeof(int));
	free(temp);
}

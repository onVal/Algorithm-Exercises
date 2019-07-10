#include "sorting.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

void selection_sort(int *array, int len) {
    int j, i, min;

    for (j=0; j <= len-1; j++) {
        min = j;
     for (i=j+1; i < len; i++) {
         if (array[i] < array[min])
            min = i;
     }
     swap (&array[min], &array[j]);
    //  print_array(array, len);
    }
}

void insertion_sort(int *array, int len) {
    int k, x;

    if (len <= 1) return;

    for (int j=0; j < len-1; j++) {
        k = j+1;
        x = array[k];

        while (k > 0 && x < array[k-1]) {
            array[k] = array[k-1];
            --k;
        }

        array[k] = x;
        // print_array(array, len);
    }
}

void bubble_sort(int *array, int len) {
    int i, j;

    for (i=0; i < len; i++) {
        for (j=0; j < len-1; j++) {
            if (array[j] > array[j+1])
               swap(&array[j], &array[j+1]);
        }
    }
}

void quick_sort(int *array, int low, int high) {
	if (low < high) {
		int p = partition(array, low, high);
		quick_sort(array, low, p-1);
		quick_sort(array, p+1, high);
	}
}

//last element is pivot
int partition(int *array, int low, int high) {
	int pivot = array[high];
	int i = low;

	for (int j = low; j < high; j++) {
		if (array[j] < pivot) {
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return i;
}

void merge_sort(int *array, int start, int end) {
	if (start < end) {
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
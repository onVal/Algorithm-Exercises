#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alg_utils.h"

#define LENGTH 10

void insertion_sort(int *, int);

int main() {
    int array[LENGTH] = {5, 10, 82, 0, -2, -6, 8, 14, 5, 7};

    insertion_sort(array, LENGTH);
    print_array(array, LENGTH);

    return 0;
}

void insertion_sort(int *array, int len) {
    int j, k, x;

    if (len == 1) return;

    for (j=0; j < len-1; j++) {
		k = j+1;
		x = array[k];

        while (k >= 0 && x < array[k-1]) {
            array[k] = array[k-1];
            --k;
        }
        array[k] = x;
	}
}

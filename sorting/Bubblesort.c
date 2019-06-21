#include <stdio.h>
#include "utils.h"

void bubble_sort(int *, int);

int main() {
    int array[10] = {5, 10, 77, 1, -2, -61, 18, 14, 57, 7};
    bubble_sort(array, 10);
    print_array(array, 10);
    return 0;
}

void bubble_sort(int *array, int len) {
    int i, j;

    for (i=0; i < len; i++) {
        for (j=0; j < len; j++) {
            if (array[j] > array[j+1])
               swap(&array[j], &array[j+1]);
        }
    }
}

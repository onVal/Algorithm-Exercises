#include <stdio.h>
#include "alg_utils.h"

void selection_sort(int *, int);

int main() {
    int array[10] = {5, 10, 82, 0, -2, -6, 8, 14, 5, 7};
    selection_sort(array, 10);
    print_array(array, 10);
    return 0;
}

void selection_sort(int *array, int len) {
    int j, i, min;
    for (j=0; j <= len-2; j++) {
        min = j;
     for (i=j+1; i < len-1; i++) {
         if (array[i] < array[min])
            min = i;
     }
     swap (&array[min], &array[j]);
    }
}

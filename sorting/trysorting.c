#include "sorting.h"
#include "utils.h"
#include <stdio.h>

#define LENGTH 10

int main() {
    int array[LENGTH] = {5, 10, 82, 0, -2, -7, 9, 14, 5, 7};

    printf("Before sorting -> ");
    print_array(array, LENGTH);

    selection_sort(array, LENGTH);
    printf("Selection sort -> ");
    print_array(array, LENGTH);

    int array2[LENGTH] = {5, 10, 82, 0, -2, -7, 9, 14, 5, 7};
    insertion_sort(array2, LENGTH);
    printf("Insertion sort -> ");
    print_array(array2, LENGTH);

    int array3[LENGTH] = {5, 10, 82, 0, -2, -7, 9, 14, 5, 7};
    bubble_sort(array3, LENGTH);
    printf("Bubble sort    -> ");
    print_array(array3, LENGTH);

    int array4[LENGTH] = {5, 10, 82, 0, -2, -7, 9, 14, 5, 7};
    quick_sort(array4, 0, LENGTH);
    printf("Quick sort     -> ");
    print_array(array4, LENGTH);

    int array5[LENGTH] = {5, 10, 82, 0, -2, -7, 9, 14, 5, 7};
    merge_sort(array5, 0, LENGTH-1);
    printf("Merge sort     -> ");
    print_array(array5, LENGTH);
    
    
    return 0;
}
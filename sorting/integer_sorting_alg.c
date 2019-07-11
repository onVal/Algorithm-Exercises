#include "sorting.h"
#include "utils.h"

#define LENGTH 7


int main() {
    int array[LENGTH] = {2, 7, 1, 2, 5, 4, 3};
    print_array(array, LENGTH);
    integer_sort(array, LENGTH);
    print_array(array, LENGTH);
}
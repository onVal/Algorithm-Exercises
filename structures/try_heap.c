#include "heap.h"
#include "utils.h"
#include <stdio.h>
int main () {
    Heap *heap = create_empty_heap();
    int input[11] = {7, 6, 1, 20, 3, 14, 12, 0, 8, 10, 15};
    int length = sizeof(input) / sizeof(int);

    for (int i=0; i < length; i++) {
        insert_heap_elem(heap, input[i]);
    }
    print_array(heap->array, heap->last_value+1);

    while(heap->last_value != -1) {
        printf("item popped: %d\n", pop_from_heap(heap));
        print_array(heap->array, heap->last_value+1);
    }

    return 0;
}
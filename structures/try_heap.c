#include "heap.h"
#include "utils.h"
int main () {
    Heap *heap = create_empty_heap();

    insert_heap_elem(heap, 7);
    insert_heap_elem(heap, 6);
    insert_heap_elem(heap, 1);
    print_array(heap->array, heap->last_value+1);

    insert_heap_elem(heap, 10);
    print_array(heap->array, heap->last_value+1);

    insert_heap_elem(heap, 15);

    print_array(heap->array, heap->last_value+1);
    return 0;
}
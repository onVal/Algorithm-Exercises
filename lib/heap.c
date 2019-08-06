#include "heap.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define DEFAULT_HEAP_SIZE 10

Heap *create_empty_heap() {
    Heap *heap = malloc(sizeof(Heap *));

    heap->heap_array = malloc(DEFAULT_HEAP_SIZE * sizeof(int));
    heap->last_value = -1;
    heap->length = DEFAULT_HEAP_SIZE;

    return heap;
}

void insert_heap_elem(Heap *heap, int value) {
    if (heap == NULL)
        heap = create_empty_heap();
    
    if (heap->last_value == heap->length) {
        heap->heap_array = realloc(heap->heap_array, heap->length * 2);
        heap->length *= 2;
    }

    heap->last_value++;
    heap->heap_array[heap->last_value] = value;

    // reposition element to maintain heap property
    int cur_value = heap->last_value;
    int parent_value;

    while(cur_value != 0) {
        parent_value = (int)ceil((cur_value - 2) / 2.0);
        printf("cur_value index = %d\tparent index = %d\n", cur_value, parent_value);

        if (heap->heap_array[cur_value] > heap->heap_array[parent_value]) {
            swap(&(heap->heap_array[cur_value]), &(heap->heap_array[parent_value]));
            cur_value = parent_value;
        } else
            break;
    }
}

int delete_heap_elem(Heap *heap) {
    return 0;
}
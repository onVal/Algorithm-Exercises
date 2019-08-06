#include "heap.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define DEFAULT_HEAP_SIZE 10

Heap *create_empty_heap() {
    Heap *heap = malloc(sizeof(Heap *));

    heap->array = malloc(DEFAULT_HEAP_SIZE * sizeof(int));
    heap->last_value = -1;
    heap->length = DEFAULT_HEAP_SIZE;

    return heap;
}

void insert_heap_elem(Heap *heap, int value) {
    if (heap == NULL)
        heap = create_empty_heap();
    
    if (heap->last_value == heap->length) {
        heap->array = realloc(heap->array, heap->length * 2);
        heap->length *= 2;
    }

    heap->last_value++;
    heap->array[heap->last_value] = value;

    // reposition element to maintain heap property
    int cur_index = heap->last_value;
    int parent_index;

    while(cur_index != 0) {
        parent_index = (int)ceil((cur_index - 2) / 2.0);

        if (heap->array[cur_index] > heap->array[parent_index]) {
            swap(&(heap->array[cur_index]), &(heap->array[parent_index]));
            cur_index = parent_index;
        } else
            break;
    }
}

int delete_heap_elem(Heap *heap) {
    return 0;
}
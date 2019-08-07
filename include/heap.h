#pragma once

typedef struct heap_t {
    int *array;
    int last_value;
    int length;
} Heap;

//max heap implementation
Heap *create_empty_heap();
void insert_heap_elem(Heap *heap, int value);
int pop_from_heap(Heap *heap);
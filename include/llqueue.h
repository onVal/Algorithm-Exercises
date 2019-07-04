#pragma once
#include "linked_list.h"

void enqueue(linked_list **, void* val);

// Sets err to -1 if queue is empty
void *dequeue(linked_list **, int *err);
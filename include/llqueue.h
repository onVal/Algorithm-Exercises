#include "linked_list.h"

#ifndef LLQUEUE_HEADER
#define LLQUEUE_HEADER

void push(linked_list **, int val);

// Sets err to -1 if queue is empty
int pop(linked_list **, int *err);
#endif
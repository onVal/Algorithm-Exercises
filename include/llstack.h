//integer stack
//stack implementation with a linked list
#pragma once
#include "linked_list.h"

//insert value on stack
void push(linked_list **root, int x);

//returns popped value
//sets err to -1 if stack is empty
int pop(linked_list **root, int *err);

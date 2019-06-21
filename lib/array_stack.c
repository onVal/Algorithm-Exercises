#include "array_stack.h"

//returns -1 if array is full, 0 means it's all ok
//index is the current position
int push(int **array, int *index, int maxlen, int value) {
	if (*index >= maxlen)
        return -1;

    (*array)[*index] = value;
    *index = *index + 1;
    return 0;
}

//if it's empty, does sets index at -1, and returns -1
int pop(int **array, int *index) {
    if (*index > 0) {
        --(*index);
        return (*array)[*index];
    }
    //this runs if stack is empty
    *index = -1;
    return -1;
}




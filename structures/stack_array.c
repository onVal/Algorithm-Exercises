#include "utils.h"
#include "array_stack.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 15

int main () {
	int *stack = malloc(MAX_STACK_SIZE * sizeof(int));
	int len = 0;

	print_array(stack, len);
	push(&stack, &len, MAX_STACK_SIZE, 6);
	print_array(stack, len);
	push(&stack, &len, MAX_STACK_SIZE, 9);
	print_array(stack, len);

	int popped = pop(&stack, &len);

	if (len == -1 && popped == -1)
		printf("Stack is empty");
	else
		printf("Popped %d from stack\n", popped);
	
	print_array(stack, len);
}

//Implement stack structure as an array

#include <stdio.h>
#include "../utils/alg_utils.h"

#define LENGTH 10

typedef enum {FALSE, TRUE} boolean;

boolean push(int *array, int value);
int pop(int *array);

int main() {
	int array[LENGTH] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	if (push(array, 9)) print_array(array, LENGTH);
	if (push(array, 5)) print_array(array, LENGTH);
	if (push(array, 12)) print_array(array, LENGTH);

	int p;
	if ((p = pop(array)) != -1)
		printf("%d popped from array\n", p);
	print_array(array, LENGTH);

	return 0;
}

boolean push (int *array, int value) {
	int i;	
	for (i=0; i < LENGTH; i++) {
		if (array[i] == -1) {
			array[i] = value;
			return TRUE;
		}
	}

	return FALSE;
}

int pop(int *array) {
	int i;
	int p = -1;

	for (i=LENGTH-1; i >= 0; i--) {
		if (array[i] != -1) {
			p = array[i];
			array[i] = -1;
			break;
		}
	}

	return p;
}

#include <stdio.h>
#include "utils.h"

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void print_array(int *array, int len) {
    if (len == 0) {
        printf("<Empty>\n");
        return;
    }

    int i;
    for (i=0; i < len; i++) {
        if (i > 0) printf(", "); 
        printf("%d", array[i]);
    }
   printf("\n"); 
}


int getsize(char *array) {
	int i = 0;

	while (array[i] != '\n' && array[i] != '\0')
		i++;

	return i;
}

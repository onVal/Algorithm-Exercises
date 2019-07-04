#include "utils.h"
#include "llstack.h"
#include <stdio.h>

void print_c(void *num);

int main () {
	linked_list *root;
	root = NULL;

	int i;
	for (i = 0; i < 10; i++) {
		push(&root, 'A'+i);
	}

	print_ll(root, &print_c);

	int popped;

	while ((popped = pop(&root)) != NULL) {
			print_c(popped);
			printf(" popped!\n");
	}
	printf("Finished popping!\n");

	print_ll(root, &print_c);
	return 0;
}

void print_c(void *num) {
	printf("%c", num);
}
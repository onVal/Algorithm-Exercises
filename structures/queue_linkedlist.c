#include "utils.h"
#include "linked_list.h"
#include "llqueue.h"
#include <stdio.h>

int main () {
	linked_list *root;
	root = NULL;

	int i, popped;
	for (i = 0; i < 10; i++) {
		push(&root, i*5);
	}

	print_ll(root);

	int e = 0;

	while (e != -1) {
		popped = pop(&root, &e);
		if (e != -1) {
			printf("%d popped!\n", popped);
		}
	}

	if (e == -1)
		printf("Finished popping!\n");

	print_ll(root);
	return 0;
}

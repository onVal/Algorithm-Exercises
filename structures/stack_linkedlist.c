#include "utils.h"
#include "llstack.h"
#include <stdio.h>

int main () {
	linked_list *root;
	root = NULL;

	int i;
	for (i = 0; i < 10; i++) {
		push(&root, i*5);
	}

	print_ll(root);

	int e = 0;
	int popped;

	while (e != -1) {
		popped = pop(&root, &e);
		if (e != -1)
			printf("%d popped!\n", popped);
	}

	if (e == -1)
		printf("Finished popping!\n");

	print_ll(root);
	return 0;
}

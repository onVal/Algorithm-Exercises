#include "linked_list.h"
#include <stdio.h>

void print_ll(linked_list *root, void (*print_fun)(void *)) {
	linked_list *current = root;
	while (current != NULL) {
		printf("-> ");
		(*print_fun)(current->x);
		printf(" ");
		current = current->next;
	}

	printf("-> NULL\n");
}

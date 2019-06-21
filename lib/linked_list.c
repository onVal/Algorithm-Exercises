#include "linked_list.h"
#include <stdio.h>

void print_ll(linked_list *root) {
	linked_list *current = root;

	while (current != NULL) {
		printf("-> %d ", current->x);
		current = current->next;
	}

	printf("-> NULL\n");
}
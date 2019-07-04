#include <stdlib.h>
#include "llstack.h"

//insert value on stack
void push(linked_list **root, int x) {
	if (*root == NULL) {
		*root = malloc(sizeof(linked_list));
		(*root)->x = x;
		(*root)->next = NULL;
		return;
	}

	linked_list *current = *root;

	while (current->next != NULL) {
		current = current->next;
	}

	current->next = malloc(sizeof(linked_list));
	current->next->x = x;
	current->next->next = NULL;
}

//return popped value
//returns and sets err = -1 if can't pop
int pop(linked_list **root, int *err) {
	int value;

	if (*root == NULL) {
		*err = -1;
		return -1;
	}

	if ((*root)->next == NULL) {
		value = (*root)->x;
		free(*root);
		*root = NULL;
		return value;
	}

	linked_list *current = *root;

	while(current->next->next != NULL) {
		current = current->next;
	}

	value = current->next->x;
	free(current->next);
	current->next = NULL;
	return value;
}

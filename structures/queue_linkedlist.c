#include "utils.h"
#include "llqueue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_t {
	int value;
	struct tree_t *kid1;
	struct tree_t *kid2;
	struct tree_t *kid3;
} tree_t;

void print_integer(void *num);
void print_char(void *num);
void print_node(void *node);

int main () {
	linked_list *root = NULL;


	void (*print_int)(void *) = &print_integer;
	void (*print_c)(void *) = &print_char;
	void (*print_n)(void *) = &print_node;

	tree_t *albero = NULL;

	int i;
	void *popped;
	for (i = 0; i < 10; i++) {
		albero = malloc(sizeof(tree_t));
		albero->value = 3 + i;
		enqueue(&root, albero);
	}

	print_ll(root, print_n);

	while ((popped = dequeue(&root)) != NULL) {
		(*print_n)(popped);
		printf(" popped!\n");
	}

	printf("Finished popping!\n");

	print_ll(root, print_n);
	return 0;
}

void print_integer(void *num) {
	printf("%d", num);
}

void print_char(void *num) {
	printf("%c", num);
}

void print_node(void *node) {
	if (((tree_t *)node) != NULL) {
		printf("%d", ((tree_t*)node)->value);
	}
}
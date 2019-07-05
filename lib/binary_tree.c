#include <stdlib.h>
#include <stdio.h>
#include "llqueue.h"
#include "llstack.h"
#include "binary_tree.h"

bin_node_t *create_tree_node(int value) {
    bin_node_t *node = malloc(sizeof(bin_node_t));
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

bin_node_t *generate_sample_tree() {
    bin_node_t *root = create_tree_node(8);

	root->left = create_tree_node(14);
	root->right = create_tree_node(1);

    root->left->left = create_tree_node(22);
    root->left->right = create_tree_node(13);
    root->right->right = create_tree_node(15);

    root->left->right->left = create_tree_node(1);
    root->left->right->right = create_tree_node(3);

	return root;
}


void traverse_tree(bin_node_t *root, void (*print_node)(void *), TraverseStrategy strat) {
    linked_list *list = NULL;
	int empty_queue = 0;

	void (*add)(linked_list **, void *) = (strat == BFS) ? &enqueue : &push;
	void *(*remove)(linked_list **) = (strat == BFS) ? &dequeue : &pop;

	add(&list, root);

	bin_node_t *current;
	printf("Tree: ");
	
	while((current = remove(&list)) != NULL) {
		(*print_node)(current);
		
        if (current->right != NULL) add(&list, current->right);
		if (current->left != NULL) add(&list, current->left);
	}

	printf("\n");
}
void print_node(void *node) {
    if (((bin_node_t *)node) != NULL) {
		printf("-> %d ", ((bin_node_t*)node)->value);
	}
}
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main() {
	void (*print_n)(void *) = &print_node;
	bin_node_t* albero = generate_sample_tree(&albero);
	// traverse_tree(albero, print_n, BFS);
	// traverse_tree(albero, print_n, DFS);

	printf("Tree in PREFIX: ");
	dfs_recursive(albero, PREFIX);
	printf("\n");
	
	printf("Tree in POSTFIX: ");
	dfs_recursive(albero, POSTFIX);
	printf("\n");

	printf("Tree in SIMMETRIC: ");
	dfs_recursive(albero, SIMMETRIC);
	printf("\n");

	printf("This tree has %d nodes\n", num_nodes(albero));
	return 0;
}
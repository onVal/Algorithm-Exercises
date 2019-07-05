#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main() {
	void (*print_n)(void *) = &print_node;
	bin_node_t* albero = generate_sample_tree(&albero);
	traverse_tree(albero, print_n, BFS);
	traverse_tree(albero, print_n, DFS);

	return 0;
}
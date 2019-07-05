#pragma once

typedef struct bin_node_t {
	int value;
	struct bin_node_t *left;
	struct bin_node_t *right;
} bin_node_t;

typedef enum TraverseStrategy {BFS, DFS} TraverseStrategy;

bin_node_t *generate_sample_tree();
bin_node_t *create_tree_node(int value);
void traverse_tree(bin_node_t *root, void (*)(void *), TraverseStrategy);
void print_node(void *node);
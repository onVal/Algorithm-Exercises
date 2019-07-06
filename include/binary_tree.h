#pragma once

typedef struct bin_node_t {
	int value;
	struct bin_node_t *left;
	struct bin_node_t *right;
} bin_node_t;

typedef enum TraverseStrategy {BFS, DFS} TraverseStrategy;
typedef enum DFS_Strategy {PREFIX, POSTFIX, SIMMETRIC} DFS_Strategy;

bin_node_t *generate_sample_tree();
bin_node_t *create_tree_node(int value);
void traverse_tree(bin_node_t *root, void (*)(void *), TraverseStrategy);
void dfs_recursive(bin_node_t *tree, DFS_Strategy);
void print_node(void *node);
int num_nodes(bin_node_t *tree);

void ins_bsearch_tree(bin_node_t **root, int value);
bin_node_t *find_node_bsearch_tree(bin_node_t *node, int value);
// void del_bsearch_tree(bin_node_t **root, int value);

//return -1 if it's empty
int max_bsearch_tree(bin_node_t *root);
#pragma once

typedef struct bin_node_t {
	int value;
	struct bin_node_t *left;
	struct bin_node_t *right;
} bin_node_t;

typedef enum TraverseStrategy {BFS, DFS} TraverseStrategy;
typedef enum DFS_Strategy {PREFIX, POSTFIX, SIMMETRIC} DFS_Strategy;

//This structure is solely used to help implement avl tree rotations on insertion
typedef enum ChildPosition {LEFT, RIGHT, NONE} ChildPosition;

typedef struct avl_node_t {
    bin_node_t *node;
    bin_node_t *parent;
    ChildPosition pos;
} avl_node_t;

bin_node_t *gen_sample_tree();

bin_node_t *create_tree_node(int value);
void traverse_tree(bin_node_t *root, void (*)(void *), TraverseStrategy);
void dfs_recursive(bin_node_t *tree, DFS_Strategy);
void print_node(void *node);
int num_nodes(bin_node_t *tree);

//binary search tree specific functions
void ins_bsearch_tree(bin_node_t **root, int value);

//avl tree specific functions
avl_node_t *create_avl_node(bin_node_t *node, bin_node_t *parent, ChildPosition pos);
void ins_avl_tree(bin_node_t **root, int value);
int is_node_balanced(bin_node_t *tree);

int tree_h_recursive_proc(bin_node_t *tree);
int tree_height(bin_node_t *tree);

bin_node_t *find_node_bsearch_tree(bin_node_t *node, int value);
int del_bsearch_tree(bin_node_t **root, int value);
int max_bsearch_tree(bin_node_t *root);
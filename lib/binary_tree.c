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

void dfs_recursive(bin_node_t *tree, DFS_Strategy strat) {
    if (tree == NULL) return;

    switch (strat) {
        case PREFIX:    
            printf("-> %d ", tree->value);
            if (tree->left != NULL) dfs_recursive(tree->left, strat);
            if (tree->right != NULL) dfs_recursive(tree->right, strat);
            break;
        case POSTFIX:
            if (tree->left != NULL) dfs_recursive(tree->left, strat);
            if (tree->right != NULL) dfs_recursive(tree->right, strat);
            printf("-> %d ", tree->value);
            break;
        case SIMMETRIC:
            if (tree->left != NULL) dfs_recursive(tree->left, strat);
            printf("-> %d ", tree->value);
            if (tree->right != NULL) dfs_recursive(tree->right, strat);
            break;
        default:
            fprintf(stderr, "Invalid DFS Strategy\n");
    }
}
void print_node(void *node) {
    if (node != NULL) {
		printf("-> %d ", ((bin_node_t*)node)->value);
	}
}

int num_nodes(bin_node_t *tree) {
    if (tree == NULL)
        return 0;
    
    int n1 = num_nodes(tree->left);
    int n2 = num_nodes(tree->right);
    return n1 + n2 + 1;
}

void ins_bsearch_tree(bin_node_t **root, int value) {
    if (*root == NULL) {
        *root = create_tree_node(value);
        return;
    }

    bin_node_t *current = *root;

    while (current != NULL) {
        if (value == current->value) return; //doesn't allow duplicate items

        if (value > current->value) {
            if (current->right != NULL)
                current = current->right;
            else {
                current->right = create_tree_node(value);
                return;
            }
        } else {
            if (current->left != NULL)
                current = current->left;
            else {
                current->left = create_tree_node(value);
                return;
            }
        }
    }
}

bin_node_t *find_node_bsearch_tree(bin_node_t *node, int value) {
    if (node == NULL) return NULL;

    if (value == node->value)
        return node;
    
    return 
        find_node_bsearch_tree((value > node->value) ? node->right : node->left, value);
}

//return -1 if item doesn't exist, 0 otherwise
int del_bsearch_tree(bin_node_t **root, int value) {
    // find node to delete and it's parent
    bin_node_t *parent = NULL;
    bin_node_t *node = *root;

    while (node != NULL) {
        if (value == node->value) break;
        parent = node;
        node = (value > node->value) ? node->right : node->left;
    }
    if (node == NULL) return -1;

    if (node->left == NULL && node->right == NULL) {
        if (parent != NULL) {
            if (parent->value < node->value)
                parent->right = NULL;
            else
                parent->left = NULL;
        } else {
            *root = NULL;
        }
        free(node);
    } else if (node->left == NULL && node->right != NULL) {
        if (parent != NULL) {
            if (parent->value < node->value)
                parent->right = node->right;
            else
                parent->left = node->right;
        } else {
            *root = node->right;
        }
        
        free(node);
    } else if (node->left != NULL && node->right == NULL) {
        if (parent != NULL) {
        if (parent->value < node->value)
            parent->right = node->left;
        else
            parent->left = node->left;
        } else {
            *root = node->left;
        }
        free(node);
    } else if (node->left != NULL && node->right != NULL) {
        bin_node_t *parent = node;
        bin_node_t *substitute = node->left;
        while(substitute->right != NULL) {
            parent = substitute;
            substitute = substitute->right;
        }
        
        node->value = substitute->value;

        if (substitute->left != NULL)
            parent->right = substitute->left;
        
        if (parent != node)
            parent->right = NULL;

        if (parent == node)
            parent->left = NULL;

        free(substitute);
    }
    
    return 0;
}

//return -1 if it's empty
int max_bsearch_tree(bin_node_t *tree) {
    if (tree == NULL) return -1;

    while (tree->right != NULL)
        tree = tree->right;
    
    return tree->value;
}
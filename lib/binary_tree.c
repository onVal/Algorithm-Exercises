#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "llqueue.h"
#include "llstack.h"
#include "binary_tree.h"

#define max(a,b) \
       ({ typeof (a) _a = (a); \
           typeof (b) _b = (b); \
         _a > _b ? _a : _b; })

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

avl_node_t *create_avl_node(bin_node_t *node, bin_node_t *parent, ChildPosition pos) {
    avl_node_t *avl_node = malloc(sizeof(avl_node_t));
    avl_node->node = node;
    avl_node->parent = parent;
    avl_node->pos = pos;
    return avl_node;
}

void ins_avl_tree(bin_node_t **root, int value) {
    if (*root == NULL) {
        *root = create_tree_node(value);
        return;
    }

    /* This stack will hold all the nodes (with their left/right relative 
       position to their parents) that the algorithm traverses */
    linked_list *avl_stack = NULL;

    bin_node_t *current = *root;
    bin_node_t *parent = NULL;

    avl_node_t *avl_node = create_avl_node(current, parent, NONE);
    push(&avl_stack, avl_node);

    //Normal insertion, keeping track of all nodes traversed
    while (current != NULL) {
        if (value == current->value) break; //doesn't allow duplicate items

        if (value > current->value) {
            if (current->right != NULL) {
                parent = current;
                current = current->right;
                avl_node = create_avl_node(current, parent, RIGHT);
                push(&avl_stack, avl_node);
            } else {
                current->right = create_tree_node(value);
                avl_node = create_avl_node(current->right, current, RIGHT);
                push(&avl_stack, avl_node);
                break;
            }
        } else {
            if (current->left != NULL) {
                parent = current;
                current = current->left;
                avl_node = create_avl_node(current, parent, LEFT);
                push(&avl_stack, avl_node);
            }
            else {
                current->left = create_tree_node(value);
                avl_node = create_avl_node(current->left, current, LEFT);
                push(&avl_stack, avl_node);
                break;
            }
        }
    }

    //Sets x, y and z variables as the three latest nodes traversed
    avl_node_t *x = pop(&avl_stack);
    avl_node_t *y = pop(&avl_stack);
    avl_node_t *z = pop(&avl_stack);

    //Checks if z node is balanced, otherwise goes up the tree until finds one
    int balanced = 1;

    while (z != NULL) {
        if (!(balanced = is_node_balanced(z->node))) {
            break;
        } else {
            // swifts the x, y, z variables up the tree
            x = y;
            y = z;
            z = pop(&avl_stack);
        }
    }

    if (balanced) return;

    // In case the tree ain't balanced, balance it!
    // Selects the correct strategy to balance the tree
    ChildPosition y_z = y->pos;
    ChildPosition x_y = x->pos;

    if (y_z == LEFT && x_y == LEFT) {
        // right rotation on z
        if (z->node != *root) {
            // z's parent points to y
            if (z->pos == LEFT)
                z->parent->left = y->node;
            else if (z->pos == RIGHT)
                z->parent->right = y->node;
        } else {
            *root = y->node;
        }
        z->node->left = y->node->right;
        y->node->right = z->node;
        
    } else if (y_z == RIGHT && x_y == RIGHT) {
        // left rotation on z
        if (z->node != *root) {
            // z's parent points to y
            if (z->pos == LEFT)
                z->parent->left = y->node;
            else if (z->pos == RIGHT)
                z->parent->right = y->node;
        } else {
            *root = y->node;
        }
        z->node->right = y->node->left;
        y->node->left = z->node;

    } else if (y_z == RIGHT && x_y == LEFT) {
        // 1. right rotation on y
        z->node->right = x->node;
        x->node->right = y->node;
        y->node->left = NULL;

        // 2. left rotation on z
        if (z->node != *root) {
            // z's parent points to y
            if (z->pos == LEFT)
                z->parent->left = x->node;
            else if (z->pos == RIGHT)
                z->parent->right = x->node;
        } else {
            *root = x->node;
        }
        z->node->right = x->node->left;
        x->node->left = z->node;

    } else if (y_z == LEFT && x_y == RIGHT) {
        // 1. left rotation on y
        z->node->left = x->node;
        x->node->left = y->node;
        y->node->right = NULL;

        // 2. right rotation on z
        if (z->node != *root) {
            // z's parent points to y
            if (z->pos == LEFT)
                z->parent->left = x->node;
            else if (z->pos == RIGHT)
                z->parent->right = x->node;
        } else {
            *root = x->node;
        }
        z->node->left = x->node->right;
        x->node->right = z->node;
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

int tree_h_recursive_proc(bin_node_t *tree) {
    if (tree == NULL)
        return 0;
    
    return max(tree_h_recursive_proc(tree->left), 
                tree_h_recursive_proc(tree->right)) + 1;
}

//returns -1 when tree is non existent
int tree_height(bin_node_t *tree) {
    if (tree == NULL)
        return -1;
    else if (tree->left == NULL && tree->right == NULL)
        return 0;
    else
        return tree_h_recursive_proc(tree) - 1;
}

//return 0 (false) if not balanced, 1 (true) otherwise
int is_node_balanced(bin_node_t *tree) {
    int left_h = tree_height(tree->left);
    int right_h = tree_height(tree->right);

    return !(abs(left_h - right_h) > 1);
}

//return -1 if it's empty
int max_bsearch_tree(bin_node_t *tree) {
    if (tree == NULL) return -1;

    while (tree->right != NULL)
        tree = tree->right;
    
    return tree->value;
}
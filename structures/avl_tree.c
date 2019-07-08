#include "binary_tree.h"
#include <stdio.h>

int main() {
    bin_node_t *avl = NULL;

    int elements[] = {7, 3, 21, 2, 12, 16, 15, 29, 28, 30};

    for (int i=0; i < sizeof(elements) / sizeof(elements[0]); i++) {
        ins_avl_tree(&avl, elements[i]);
        traverse_tree(avl, &print_node, BFS);
    }

    if (is_node_balanced(avl))
        printf("Is balanced (root)\n");
    else
        printf("Not balanced (root)\n");
    
    printf("Tree height: %d\n", tree_height(avl));
    printf("Tree height (from 12): %d\n", tree_height(avl->left));
    printf("Tree height (from 16): %d\n", tree_height(avl->left->right));

}
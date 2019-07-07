#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void find_in_tree(bin_node_t *, int value);
void rm_helper(bin_node_t **, int value);

int main() {
    bin_node_t *bst = NULL;
    // int elements[] = {5, 1, 3, 8, 2, 10, 7};
    int elements[] = {7, 3, 21, 2, 12, 16, 15, 29, 28, 30};

    for (int i=0; i < sizeof(elements) / sizeof(elements[0]); i++)
        ins_bsearch_tree(&bst, elements[i]);
    
    find_in_tree(bst, 15);

    printf("Full tree:\n");
    traverse_tree(bst, &print_node, BFS);
    printf("\n");
    
    rm_helper(&bst, 15);
    rm_helper(&bst, 30);
    rm_helper(&bst, 2);
    rm_helper(&bst, 21);
    rm_helper(&bst, 16);
    rm_helper(&bst, 29);
    rm_helper(&bst, 28);
    rm_helper(&bst, 7);
    rm_helper(&bst, 3);
    rm_helper(&bst, 15);
    rm_helper(&bst, 12);

    find_in_tree(bst, 7);
    
    return 0;
}

void find_in_tree(bin_node_t *tree, int value) {
    bin_node_t *found = malloc(sizeof(bin_node_t));
    found = find_node_bsearch_tree(tree, value);

    if (found == NULL)
        printf("%d not found\n", value);
    else
        printf("node value found: %d\n", found->value);
}

void rm_helper(bin_node_t **tree, int value) {
    printf("Remove %d:\n", value);
    if (del_bsearch_tree(tree, value) == -1)
        printf("No element deleted\n");
    traverse_tree(*tree, &print_node, BFS);
    printf("\n");
}
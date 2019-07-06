#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    bin_node_t *bst = NULL;
    int elements[] = {5, 1, 3, 8, 2, 10, 7};

    for (int i=0; i < sizeof(elements) / sizeof(elements[0]); i++)
        ins_bsearch_tree(&bst, elements[i]);

    dfs_recursive(bst, SIMMETRIC);
    printf("\nThe largest value in this tree is: %d\n", max_bsearch_tree(bst));


    bin_node_t *found = malloc(sizeof(bin_node_t));
    found = find_node_bsearch_tree(bst, 11);
    if (found == NULL)
        printf("11 not found\n");
    else
        printf("node value found: %d\n", found->value);

    found = find_node_bsearch_tree(bst, 1);
    if (found == NULL)
        printf("1 not found\n");
    else
        printf("node value found: %d\n", found->value);

    found = find_node_bsearch_tree(bst, 8);
    if (found == NULL)
        printf("8 not found\n");
    else
        printf("node value found: %d\n", found->value);
    

    return 0;
}
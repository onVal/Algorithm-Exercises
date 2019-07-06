#include "binary_tree.h"
#include <stdio.h>

int main() {
    bin_node_t *bst = NULL;
    int elements[] = {5, 1, 3, 8, 2, 10, 7};

    for (int i=0; i < sizeof(elements) / sizeof(elements[0]); i++)
        ins_binsearch_tree(&bst, elements[i]);

    dfs_recursive(bst, SIMMETRIC);
    printf("\nThe largest value in this tree is: %d\n", max_binsearch_tree(bst));
    return 0;
}
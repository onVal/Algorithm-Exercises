#include "2_3_tree.h"
#include <stdio.h>

int main() {
    Node *tree = gen_sample_23_tree();
    LeafNode *found;

    for (int i=0; i < 100; i++) {
        if ((found = find(tree, i)) != NULL)
            printf("Found element %d\n", found->value);
    }

    return 0;
}
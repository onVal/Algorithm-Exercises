#include "2_3_tree.h"
#include <stdlib.h>

Node *createLeafNode(int value) {
    Node *leaf = malloc(sizeof(Node));
    leaf->unionType = LEAF;
    leaf->node.leafNode.value = value;
    return leaf;
}

Node *createKeyNode(int leftKey, int centralKey) {
    Node *keynode = malloc(sizeof(Node));
    keynode->unionType = KEY;

    keynode->node.keynode.leftKey = leftKey;
    keynode->node.keynode.centralKey = centralKey;
    keynode->node.keynode.left = NULL;
    keynode->node.keynode.central = NULL;
    keynode->node.keynode.right = NULL;

    return keynode;
}

Node *gen_sample_23_tree() {
    Node *root = createKeyNode(7, 22);
    root->node.keynode.left = createKeyNode(2, -1);
    root->node.keynode.central = createKeyNode(11, 15);
    root->node.keynode.right = createKeyNode(44, -1);

    root->node.keynode.left->node.keynode.left = createLeafNode(2);
    root->node.keynode.left->node.keynode.right = createLeafNode(7);

    root->node.keynode.central->node.keynode.left = createLeafNode(11);
    root->node.keynode.central->node.keynode.central = createLeafNode(15);
    root->node.keynode.central->node.keynode.right = createLeafNode(22);

    root->node.keynode.right->node.keynode.left = createLeafNode(44);
    root->node.keynode.right->node.keynode.right = createLeafNode(56);

    return root;
}

LeafNode *find(Node *root, int value) {
    Node *current = root;

    while (current->unionType == KEY) {
        if (value <= current->node.keynode.leftKey)
            current = current->node.keynode.left;
        else if (current->node.keynode.central != NULL &&
            value <= current->node.keynode.centralKey)
            current = current->node.keynode.central;
        else
            current = current->node.keynode.right;
    }

    if (current->node.leafNode.value == value) {
        return &current->node.leafNode;
    } else {
        return NULL;
    }
}
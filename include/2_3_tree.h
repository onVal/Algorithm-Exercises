#pragma once

typedef enum UnionType {LEAF, KEY} UnionType;

struct Node {
    UnionType unionType;

    union GenericNode {
        struct LeafNode {
            int value;
        } leafNode;

        struct KeyNode {
            int leftKey;
            int centralKey;
            struct Node *left;
            struct Node *central;
            struct Node *right;
        } keynode;
    } node;
};

typedef struct Node Node;
typedef struct LeafNode LeafNode;

Node *gen_sample_23_tree();
Node *createLeafNode(int value);
Node *createKeyNode(int leftKey, int centralKey);

LeafNode *find(Node *root, int value);
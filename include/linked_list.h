#pragma once

typedef struct linked_list {
    int x;
    struct linked_list *next;
} linked_list;

void print_ll(linked_list *root);

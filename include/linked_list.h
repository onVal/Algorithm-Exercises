#pragma once

typedef struct linked_list {
    void *x;
    struct linked_list *next;
} linked_list;

void print_ll(linked_list *root, void (*print_fun)(void *));

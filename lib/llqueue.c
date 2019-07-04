#include <stdlib.h>
#include "llqueue.h"

void enqueue(linked_list **q, void *val) {
    if (*q == NULL) {
        *q = malloc(sizeof(struct linked_list));
        (*q)->x = val;
        (*q)->next = NULL;
        return;
    }

    linked_list *current = *q;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(linked_list));
    current->next->x = val;
    current->next->next = NULL;
}

void *dequeue(linked_list **q) {
    linked_list *temp;
    void *value;

    if (*q == NULL)
        return NULL;

    temp = *q;
    value = temp->x;
    (*q) = (*q)->next;
    free(temp);
    return value;
}
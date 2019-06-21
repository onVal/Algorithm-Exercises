#include <stdlib.h>
#include "llqueue.h"

void push(linked_list **q, int val) {
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

int pop(linked_list **q, int *err) {
    linked_list *temp;
    int value;

    if (*q == NULL) {
        *err = -1;
        return -1;
    } else {
        temp = *q;
        value = temp->x;
        (*q) = (*q)->next;
        free(temp);
        *err = 0;
        return value;
    }

}
//Implement stack structure as an list

#include <stdio.h>
#include <stdlib.h>
#include "../utils/alg_utils.h"

#define LENGTH 10

typedef struct node {
	int val;
	struct node *next;
} node_t;

typedef enum {FALSE, TRUE} boolean;

node_t* push(node_t *list, int value);
int pop(node_t *list);
void print_linked_list(node_t *list);

int main() {
	
	node_t *list = NULL;

	list = push(list, 5); 
	print_linked_list(list);
	push(list, 88); 
	print_linked_list(list);
	push(list, 13);
	print_linked_list(list);

	int p;
	if ((p = pop(list)) != -1)
		printf("%d popped from list\n", p);
	else
		printf("List is empty: nothing to pop\n");

	print_linked_list(list);

	return 0;
}

node_t* push (node_t *list, int value) {
	node_t* head = list;

	if (list == NULL) {
		list = malloc (sizeof(node_t));
		list->val = value;
		list->next = NULL;
		return list;
	}

	while (list->next != NULL) {
		list = list->next;
	}

	list->next = malloc (sizeof(node_t));
	list->next->val = value;
	list->next->next = NULL;
	return head;
}

int pop(node_t *list) {
	node_t *prev;
	int popped;

	if (list == NULL)
		return -1;

	while (list->next != NULL) {
		prev = list;
		list = list->next;
	}

	popped = list->val;
	free(list);
	prev->next = NULL;
	return popped;
}

void print_linked_list(node_t *list) {
	while (list != NULL) {
		printf("%d --> ", list->val);
		list = list->next;
     }
     printf("NULL\n");
 }



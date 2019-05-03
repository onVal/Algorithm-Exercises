#include <stdio.h>
#include <stdlib.h>

/* Linked list implementation: 
 * - findElementFromIndex in a linked list
 * - searchElement in a linked list
 * - appendElement in a linked list
 * - deleteElement in a linked list
 * - printElements in a linked list
 */

typedef struct node {
    int element;
    struct node *next;
} node;

//typedef enum bool{true, false} boolean;

node* appendElement(node *list, int element);
node* deleteElement(node *list, int element);
int searchElement(node *list, int element);
int findElementFromIndex(node *list, int index);

void printList(node *list);


int main() {
   	node *list = NULL;

	list = appendElement(list, 8);
    printList(list);
	
	appendElement(list, 17);
	appendElement(list, 7);
	appendElement(list, 91);
	appendElement(list, 44);
	printList(list);

	list = deleteElement(list, 91);
	list = deleteElement(list, 8);
	printList(list);

	list = deleteElement(list, 55);
	list = appendElement(list, 62);
	printList(list);

	int n = 17;
	int pos = searchElement(list, n);
	if (pos != -1)
		printf("%d has been found in position %d\n", n, pos);
	else
		printf("%d is not present in the list\n", n);

	printf("The element at position %d is %d\n", 3, findElementFromIndex(list, 3));
	printf("The element at position %d is %d\n", 5, findElementFromIndex(list, 5));
	printf("The element at position %d is %d\n", 1, findElementFromIndex(list, 1));

	return 0;
}

node* appendElement(node *list, int element) {
   if (list == NULL) {
   	list = malloc(sizeof(node));
	list->element = element;
	list->next = NULL;
    return list;
   }

   node *current = list;

   while (current->next != NULL) {
   	current = current->next;
   }

   current->next = malloc(sizeof(node));
   current->next->element = element;
   current->next->next = NULL;
   return list;
}

node* deleteElement(node *list, int element) {
	node *current = list;
	node *prev = NULL;

	while (current != NULL) {
		if (current->element == element) {
			if (prev == NULL) {
				prev = current->next;
				free(current);
				return prev;
			} else {
				prev->next = current->next;
				free(current);
				return list;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
	
	return list;
}

int searchElement(node *list, int element) {
	int i = 0;

	while (list != NULL) {
		if (list->element == element)
			return i;

		list = list->next;
		++i;
	}
	
	return -1;
}

int findElementFromIndex(node *list, int index) {
	int i = 0;
	while (list != NULL && i < index) {
		list = list->next;
		++i;
	}

	if (list != NULL && i == index)
		return list->element;
	else
		return -1;
}

void printList(node *list) {
	while (list != NULL) {
		printf("%d --> ", list->element);
		list = list->next;
	}

	printf("NULL\n");
}

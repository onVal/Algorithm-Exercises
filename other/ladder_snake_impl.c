#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <llqueue.h>

#define MAX_DICE_OUTPUT 6

typedef struct node_item_t {
    int value;
    int throws;
} node_item_t;


node_item_t *createItem(int value, int throws);
int nodeValue(int *board, int length, int node_index);
int minThrows(int *board, int length, int starting_node, bool print_seq, bool ignore_ls);
void print_item(void *item);

int main() {
    char command, option;
    int *board;
    int length, value;
    int starting_node, dice_roll;

    while (command != 'f') {
        scanf("%c", &command);

        switch(command) {
            case 'R':
                scanf("%d", &length);

                board = calloc(length + 1, sizeof(int));
                
                for (int i=1; i <= length; i++) {
                    scanf("%d", &board[i]);
                }
                break;
            case 'x':
                scanf("%d%d", &starting_node, &dice_roll);
                if ((value = nodeValue(board, length, starting_node + dice_roll)) != -1)
                    printf("%d\n", value);
                break;
            case 'm':
                scanf("%c %d", &option, &starting_node);
                if (option == '-')
                    printf("%d\n", minThrows(board, length, starting_node, false, true));
                else
                    printf("%d\n", minThrows(board, length, starting_node, false, false));

                break;
            case 's':
                scanf("%c %d", &option, &starting_node);
                if (option == '-')
                    minThrows(board, length, starting_node, true, true);
                else
                    minThrows(board, length, starting_node, true, false);
                printf("\n");
                break;
            case 'f':
                break;
        }
    }
        
    return 0;
}

//this version of the algorithm enters an infinite loop 
//if board is not built correctly or a path doesn't exists
int minThrows(int *board, int length, int starting_node, bool print_seq, bool ignore_ls) {
    int next_node;
    int best_throw;
    int *visited = calloc(length, sizeof(int));

    linked_list *queue = NULL;

    node_item_t *item = createItem(starting_node, 0);
    enqueue (&queue, item);
    
    node_item_t *current_item;
    node_item_t *temp_item;

    visited[item->value] = 1;

    //breadth first search, using a queue
    while(queue != NULL) {
        current_item = dequeue(&queue);
        if (current_item == NULL) {
            continue;
        } else {
            if (current_item->value == length) {
                return current_item->throws;
            }
        }

        for (int i=0; i < MAX_DICE_OUTPUT; i++) {
            next_node = nodeValue(board, length, current_item->value + i+1);
            //SEEMS LIKE MY QUEUE LIB DOESN'T WORK TOO WELL AFTER ALL
            if (next_node <= length && visited[next_node] == 0) {
                temp_item = createItem(next_node, current_item->throws+1);
                enqueue(&queue, temp_item);
                visited[next_node] = 1;
            }
        }

        print_ll(queue, print_item);
    }

    return -1;
}

//returns -1 if invalid index
int nodeValue(int *board, int length, int node_index) {
    if (node_index > length)
        return -1;

    if (board[node_index] != 0)
        return board[node_index];
    else
        return node_index;
} 

node_item_t *createItem(int value, int throws) {
    node_item_t *item = malloc(sizeof(node_item_t));
    item->value = value;
    item->throws = throws;
    return item;
}

void print_item(void *item) {
    printf("v=%d (t=%d)", ((node_item_t *)item)->value, 
                                    ((node_item_t *) item)->throws);
}
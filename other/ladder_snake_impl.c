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
void print_sequence(void *s);

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

int minThrows(int *board, int length, int starting_node, bool print_seq, bool ignore_ls) {
    int *visited = calloc(length, sizeof(int));

    linked_list *queue = NULL;
    int throws;

    int **sequences;
    sequences = malloc(31 * sizeof(int *));
    for (int i=0; i < 31; i++) {
        sequences[i] = calloc(10, sizeof(int));
    }

    node_item_t *item = createItem(starting_node, 0);
    enqueue (&queue, item);
    
    node_item_t *current_item;
    node_item_t *temp_item;

    visited[item->value] = 1;
    int next_node;

    //breadth first search, using a queue
    while(queue != NULL) {
        current_item = dequeue(&queue);
        if (current_item == NULL) {
            continue;
        } else {
            if (current_item->value == length) {
                if (print_seq) {
                    for (int i=0; sequences[length][i] != 0; i++) {
                        printf("%d ", sequences[length][i]);
                    }
                }
                return current_item->throws;
            }
        }

        for (int i=1; i <= MAX_DICE_OUTPUT; i++) {
            
            next_node = (ignore_ls) ? current_item->value+i : 
                            nodeValue(board, length, current_item->value + i);

            if (next_node >=0 && next_node <= length && visited[next_node] == 0) {
                throws = current_item->throws;
                temp_item = createItem(next_node, throws+1);
                enqueue(&queue, temp_item);
                sequences[next_node][throws] = i;

                while (throws >= 1) {
                    sequences[next_node][throws-1] = 
                        sequences[current_item->value][throws-1];
                    throws--;
                }
                
                visited[next_node] = 1;
            }
        }
        // print_ll(queue, print_item);
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

void print_sequence(void *s) {
    printf("-> %d ", *((int *)s));
}
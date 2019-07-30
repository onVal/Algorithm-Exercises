#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int nodeValue(int *board, int length, int node_index, bool ignore_ls);
int minThrows(int *board, int length, int starting_node, bool print_seq, bool ignore_ls);

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
                if ((value = nodeValue(board, length, starting_node + dice_roll, false)) != -1)
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
    int min_throws = 0;
    int current_node = starting_node;
    int biggest_node = -1;
    int next_node;
    int best_throw;

    while (1) {
        for (int i=1; i <= 6; i++) {
            next_node = nodeValue(board, length, current_node + i, ignore_ls);
            if (next_node == length) {
                if (print_seq) printf("%d ", i); //prints last best throw
                return min_throws + 1;
            }

            if (biggest_node < next_node) {
                biggest_node = next_node;
                best_throw = i;
            }
        }

        current_node =  biggest_node;
        if (print_seq) printf("%d ", best_throw);

        min_throws++;
    }

}

//returns -1 if invalid index
int nodeValue(int *board, int length, int node_index, bool ignore_ls) {
    if (node_index > length)
        return -1;

    if (board[node_index] != 0 && !ignore_ls)
        return board[node_index];
    else
        return node_index;
} 
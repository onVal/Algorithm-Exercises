#include <stdio.h>
#include <stdlib.h>

int nodeValue(int *board, int node_index);
int minThrows(int *board, int length);

int main() {
    int length;
    scanf("%d", &length);

    int *board = calloc(length + 1, sizeof(int));

    for (int i=1; i <= length; i++) {
        scanf("%d", &board[i]);
    }

    printf("\n%d\n", minThrows(board, length));
    return 0;
}

int minThrows(int *board, int length) {
    int min_throws = 0;
    int current_node = 1;
    int biggest_node = -1;
    int next_node;


    while (1) {
        for (int i=1; i <= 6; i++) {
            next_node = nodeValue(board, current_node + i);
            if (next_node == length)
                return min_throws + 1;

            if (biggest_node < next_node)
                biggest_node = next_node;
        }

        current_node =  biggest_node;
        min_throws++;
        // biggest_node = -1;
    }

}

int nodeValue(int *board, int node_index) {
    if (board[node_index] != 0)
        return board[node_index];
    else
        return node_index;
} 
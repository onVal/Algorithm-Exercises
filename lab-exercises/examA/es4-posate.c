#include <stdio.h>

void robot() {
    char input[100];
    scanf("%s", &input);

    char left, right;
    left = right = 'E'; //'E' stands for empty

    char stack[100]; int sp = 0;
    int i = 0;
    while (input[i] != '\n') {
        if (left == 'E' && right == 'E') { //if both empty, take w/ left
            left = input[i++];
            printf("sx %c\n", left);
            continue;
        }

        if (left != 'E' && right == 'E') { // if only right empty
            if ((left == 'K' && stack[sp] == 'F') || // if stack has opposite, take it w/ right
                (left == 'F' && stack[sp] == 'K')) {
                right = stack[sp--];
                // continue;
            } else {
                right = input[i++];
            }  
        }

        if ((left == 'K' && right == 'F') ||
            (left == 'F' && right == 'K')) {
            left = 'E'; right = 'E';
            i++;
        } else {
            stack[sp++] = right;
            right = 'E';
            printf("dx push %c\n", right);
        }
    }

    return !(left == 'E' && right == 'E' && sp == 0);
}

int main() {
    printf("%d\n", robot());
}


// KK FFF K FF

// SX K
// DX K
// dx push K
// DX F 
// SX F
// dx pop K // here my code doesn't work
// SX F
// dx K
// sx F
// dx F
// dx push F

// STACK: F
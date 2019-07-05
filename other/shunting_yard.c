//The current version of this algorithm works only with two operands and 1 operation

#include "llqueue.h"
#include "llstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void shunting_yard(char *);
bool is_operator(char op);
void print_s(void *s);

int main() {
    char expr[] = "3 + 4";
    shunting_yard(expr);
    return 0;
}

void shunting_yard(char expr[]) {
    linked_list *output_queue = NULL;
    linked_list *op_stack = NULL;

    char *token = malloc(5 *sizeof(int));
    void *c;

    while ((token = strsep(&expr, " ")) != NULL) {
        if (token[1] == '\0' && is_operator(token[0])) {
            push(&op_stack, token[0]);
        } else {
            if (atoi(token))
                enqueue(&output_queue, atoi(token));
        }
    }

    while ((c = pop(&op_stack)) != NULL) {
        enqueue(&output_queue, c);
    }

    print_ll(output_queue, &print_s);
}

bool is_operator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

void print_s(void *ch) {
    if ((char *)ch != NULL) {
        if (is_operator((char *)ch))
            printf(" %c ", ((char *)ch));
        else
            printf(" %d ", (int *)ch);
    }
}
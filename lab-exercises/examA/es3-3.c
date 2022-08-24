#include <stdio.h>
#include <stdlib.h>

static int numOfCalls = 0;

typedef int bool;

typedef struct room_t {
    char *name;
    int value;
    int optimal;
    bool mark;
    struct room_t *children[10]; 
} room;

room *create_room(char *name, int value, int Nchildren);
room *init_deposit();
int optimal_implant2(room *d);
void print_implant(room *d);

int max(int a, int b) {
    return (a >= b) ? a : b;
}

int main() {
    room *deposit = init_deposit();
    printf("The optimal implant is: %d\n", optimal_implant2(deposit));
    printf("Number of calls: %d\n", numOfCalls);
    // print_implant(deposit);
}

room *init_deposit() {
    // init deposit of exam
    room *s0 = create_room("s0", 1, 1);
    room *s1 = create_room("s1", 1, 3);
    room *s2 = create_room("s2", 1, 0);
    room *s3 = create_room("s3", 100, 3);
    room *s4 = create_room("s4", 1, 0);
    room *s5 = create_room("s5", 99, 0);
    room *s6 = create_room("s6", 2, 0);
    room *s7 = create_room("s7", 2, 0);

    s0->children[0] = s1;
    s1->children[0] = s2;
    s1->children[1] = s3;
    s1->children[2] = s4;
    s3->children[0] = s5;
    s3->children[1] = s6;
    s3->children[2] = s7;

    return s0;
}

room *create_room(char *name, int value, int Nchildren) {
    room *r = malloc(sizeof(room));
    r->name = malloc(3);
    r->name = name;
    r->value = value;
    for (int i=0; i < 10; i++) {
        r->children[i] = (i < Nchildren) ? malloc(sizeof(room)) : NULL;
    }
    r->optimal = -1;
    r->mark = 0;
    return r;
}

int optimal_implant2(room *d) {
    numOfCalls += 1;
    // for room x:
    // you take it -> max[x] = x + sum of x's grandkids
    // you don't   -> max[x] = sum of x's kids
    // max [root] is the solution

    if (d->optimal != -1) {
        return d->optimal;
    } 
    
    if (d->children[0] == NULL) {
        d->optimal = d->value;
        return d->optimal;
    }

    // sum of d's kids
    int sumOfChildren = 0;
    for (int i=0; i < 10 && d->children[i] != NULL; i++) {
        sumOfChildren += optimal_implant2(d->children[i]);
    }

    // sum of d's grandkids
    // CAN I HAVE IT IN THE SAME LOOP AS THE SUM OF CHILDREN? THINK
    int sumOfGrandkids = 0;
    for (int i=0; i < 10 && d->children[i] != NULL; i++) {
        room *kid = d->children[i];
        for (int j=0; j < 10 && kid->children[j] != NULL; j++) {
            sumOfGrandkids += optimal_implant2(kid->children[j]);
        }
    }

    d->optimal = max(d->value + sumOfGrandkids, sumOfChildren);
    return d->optimal;
}


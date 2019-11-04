#include "union_find.h"
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>

//I'm assuming each element is different

// AEKCOSP

uf_t initUF(char *elements, int length) {
    char buf[2];

    uf_t uf = malloc(sizeof(uf_t));
    uf->array = malloc(length * sizeof(int));
    uf->map = init_dict(length);
    uf->length = length;

    char key[2];

    //init map and array together
    for (int i=0; i < length; i++) {
        sprintf(buf, "%d", i);

        key[0] = elements[i];
        key[1] = '\0';

        insert(uf->map, key, buf);

        uf->array[i] = i;
    }

    return uf;
}

int getElementNumber(uf_t uf, char element) {
    char strElement[2];
    strElement[0] = element;
    strElement[1] = '\0';

    char *num = getValue(uf->map, strElement);
    return atoi(num);
}

int find(uf_t uf, char element) {
    int num = getElementNumber(uf, element);

    while (num != uf->array[num]) {
        num = uf->array[num];
    }

    return num;
}

void union_f(uf_t uf, char e1, char e2) {
    int g1 = find(uf, e1);
    int g2 = find(uf, e2);

    if (g1 != g2) {
        uf->array[g2] = g1;
    }
}

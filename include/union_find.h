#pragma once
#include "dictionary.h"

typedef struct union_find {
    int *array;
    dict_t *map;
    int length;
} *uf_t;

uf_t initUF(char *elements, int length);
int find(uf_t uf, char element);
void union_f(uf_t uf, char e1, char e2);

//private function
int getElementNumber(uf_t uf, char element);

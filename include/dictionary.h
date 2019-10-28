#pragma once

typedef struct pair_t {
    char *key;
    char *value;
} pair_t;

typedef struct dict_t {
    pair_t *entries;
    int size;
} dict_t;

// pair_t *allocate_pairs(int size);
pair_t *init_htable(int size);
dict_t *init_dict(int size);

void set_value(dict_t *dict, int idx, char *value);
void set_key(dict_t *dict, int idx, char *key);
char *get_value(dict_t *dict, int idx);
char *get_key(dict_t *dict, int idx);
void set_keyvalue(dict_t *dict, int idx, char *key, char *value);

//if size is not enough, double the hash table size
void insert(dict_t *dict, char *key, char *value);

//returns NULL if value is not present
char *getValue(dict_t *dict, char *key);

unsigned long hash(char *key);
int c_hash(char *key, int i, int size);

void printValues(dict_t *dict);
void printAll(dict_t *dict);


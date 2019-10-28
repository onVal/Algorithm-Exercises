//This basic implementation uses linear probing for collisions.
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define STRING_SIZE 20

pair_t *init_htable(int size) {
    pair_t *htable = malloc(size * sizeof(pair_t));
    
    for (int i=0; i < size; i++) {
        htable[i].key = NULL;
        htable[i].value = NULL;
    }

    return htable;
}
dict_t *init_dict(int size) {
    dict_t *d = malloc(sizeof(dict_t));
    d->entries = init_htable(size);
    d->size = size;

    return d;
}

unsigned long hash(char *key) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

char *get_key(dict_t *dict, int idx) {
    return dict->entries[idx].key;
}

void set_key(dict_t *dict, int idx, char *key) {
    char *dkey;
    if ((dkey = get_key(dict, idx)) == NULL) {
        dkey = malloc(STRING_SIZE);
        dict->entries[idx].key = dkey;
    } 
    strcpy(dkey, key);
}

char *get_value(dict_t *dict, int idx) {
    return dict->entries[idx].value;
}

void set_value(dict_t *dict, int idx, char *value) {
    char *dvalue;
    if ((dvalue = get_value(dict, idx)) == NULL) {
        dvalue = malloc(STRING_SIZE);
        dict->entries[idx].value = dvalue;
    }
    strcpy(dvalue, value);
}

void set_keyvalue(dict_t *dict, int idx, char *key, char *value) {
    set_key(dict, idx, key);
    set_value(dict, idx, value);
}

int c_hash(char *key, int i, int size) {
    return (hash(key) + i) % size;
}

void insert(dict_t *dict, char *key, char *value) {
    int hashsize = dict->size;
    int offset = 0;
    
    int idx = c_hash(key, offset, hashsize);
    int initial_idx = idx;

    char *keyAtIndex;

    do {
        keyAtIndex = get_key(dict, idx);
        if (keyAtIndex == NULL || strcmp(keyAtIndex, key) == 0) {
            set_keyvalue(dict, idx, key, value);
            return;
        } 
        
        offset++;
    } while((idx = c_hash(key, offset, hashsize)) != initial_idx);

    // if it's full, double the size of the dictionary and try again
    // (it will work this time)
    dict->size *= 2;
    dict->entries = 
        realloc(dict->entries, dict->size * sizeof(pair_t));

    insert(dict, key, value);
}

char *getValue(dict_t *dict, char *key) {
    int probing_offset = 0;
    int idx = c_hash(key, probing_offset, dict->size);
    int initial_idx = idx;

    char *keyAtIndex;

    do {
        if ((keyAtIndex = get_key(dict, idx)) == NULL) {
            return NULL;
        } else if (strcmp(keyAtIndex, key) == 0) {
            return get_value(dict, idx);
        } else {
            ++probing_offset;
            idx = c_hash(key, probing_offset, dict->size);
        }
    } while(idx != initial_idx);

    return NULL;
}

void printValues(dict_t *dict) {
    char *current;

    printf("[ ");
    for (int i=0; i < dict->size; i++)
        if ((current = get_value(dict, i)) != NULL)
            printf("%s, ", current);
    
    printf(" ]\n");
}

void printAll(dict_t *dict) {
    char *current_key;

    printf("{ ");
    for (int i=0; i < dict->size; i++) {
        if ((current_key = get_key(dict, i)) != NULL) {
            printf("(%s, %s), ", current_key, get_value(dict, i));
        }
    }

    printf(" }\n");
}
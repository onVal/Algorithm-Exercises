#include "dictionary.h"
#include <stdio.h>

int main() {
    dict_t *dict = init_dict(5);

    insert(dict, "hello", "world");
    insert(dict, "giorgio", "valbo");
    insert(dict, "hello", "baby");

    printf("->giorgio's value: %s\n", getValue(dict, "giorgio"));
    printf("->bubu's value: %s\n", getValue(dict, "bubu"));
    
    insert(dict, "bubu", "yoghi");
    printf("->bubu's value: %s\n", getValue(dict, "bubu"));

    printValues(dict);
    printAll(dict);

    insert(dict, "picci", "parni");
    insert(dict, "cine", "matico");
    insert(dict, "brollina", "brollosha");

    printValues(dict);
    printAll(dict);

    return 0;
}
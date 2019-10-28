#include "dictionary.h"

int main() {
    dict_t *dict = init_dict(5);

    insert(dict, "hello", "world");
    insert(dict, "giorgio", "valbo");
    insert(dict, "hello", "baby");

    //need to try realloc as well

    return 0;
}
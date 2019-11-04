#include "union_find.h"
#include <stdio.h>

int main() {
    uf_t uff = initUF("EFIDCA", 6);
    union_f(uff, 'I', 'C');
    union_f(uff, 'E', 'I');
    union_f(uff, 'D', 'A');

    for (int i=0; i < 6; i++) {
        printf("%d, ", uff->array[i]);
    }

    return 0;
}
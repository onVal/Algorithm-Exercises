#include <stdio.h>

#define DIGIT_NUM 10

int main() {
    int n, i;
    int digit;
    int counter[DIGIT_NUM] = { 0 };

    scanf("%d", &n);

    i = 1;
    while (n != 0) {
        digit = n % 10;
        counter[digit]++;

        n /= 10;
        ++i;
    }

    int no_repeated_digits = 1;

    for (i=0; i < DIGIT_NUM; i++) {
        if (counter[i] > 1) {
            printf("%d é ripetuto %d volte!\n", i, counter[i]); 
            no_repeated_digits = 0;
        }      
    }

    if (no_repeated_digits)
        printf("Nessuna cifra ripetuta!\n");

    return 0;
}
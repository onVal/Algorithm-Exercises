// 7 I due valori più grandi
// Scrivete una funzione con prototipo void max_secondmax ( int a[], int n, int *max, int *second_max )
// che, dato un array a di lunghezza n individui il valore più grande in a e il secondo elemento per grandezza in a, e li
// memorizzi nelle variabili puntate da max e second_max.
#include <stdio.h>
#include <limits.h>

void max_secondmax ( int a[], int n, int *max, int *second_max );

int main(void) {
    int max, second_max;
    int a[100];

    printf("Insert array:\n");

    int i = 0;

    do {
        scanf("%d", &a[i]);
    } while (a[i++] != '\n');

    max_secondmax(a, i, &max, &second_max);

    printf("Max is: %d, second_max is: %d\n", max, second_max);
}

void max_secondmax ( int a[], int n, int *max, int *second_max ) {
    int i;
    *max = 0; *second_max = 0;
    
    for (i=0; i < n; i++) {
        if (a[i] > *max) {
            *second_max = *max;
            *max = a[i];
        }
        else if (a[i] > *second_max) {
            *second_max = a[i];
        }
    }
}

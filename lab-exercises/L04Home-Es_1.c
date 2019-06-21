// 1 Trasformazione orario in secondi
// Scrivete una funzione con prototipo void split_time ( long int tot_sec, int *h, int *m, int *s ) che,
// dato un orario fornito in numero di secondi dalla mezzanotte, calcoli l’orario equivalente in ore, minuti, secondi, e lo
// memorizzi nelle tre variabili puntate da (h), (m) e (s) rispettivamente.
#include <stdio.h>

void split_time (long tot_sec, int *h, int *m, int *s);

int main(void) {
    int h, m, s;
    long input;

    input = 12l;
    split_time (input, &h, &m, &s);
    printf("%ld seconds -> %dh:%dm:%ds\n", input, h, m, s);

    input = 60l;
    split_time (input, &h, &m, &s);
    printf("%ld seconds -> %dh:%dm:%ds\n", input, h, m, s);

    input = 7000l;
    split_time (input, &h, &m, &s);
    printf("%ld seconds -> %dh:%dm:%ds\n", input, h, m, s);

    return 0;
}

void split_time (long tot_sec, int *h, int *m, int *s) {
    *h = tot_sec / 3600;
    tot_sec = tot_sec % 3600;
    *m = tot_sec / 60;
    tot_sec = tot_sec % 60;
    *s = tot_sec;
}
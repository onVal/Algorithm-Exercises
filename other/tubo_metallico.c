#include <stdio.h>
#include <stdlib.h>

int min_array_idx(int *a, int n);
int maxSegm(int *s, int n, int L);

int main() {
    int L, n;
    scanf("%d%d", &L, &n);

    int *segments = malloc(n * sizeof(int));

    for (int i=0; i < n; i++)
        scanf("%d", &segments[i]);

    printf("%d", maxSegm(segments, n, L));    
    return 0;
}

int maxSegm(int *s, int n, int L) {
    int Lp = L;
    int maxSegm = 0;
    int min_idx;

    for (int i=0; i < n; i++) {
        min_idx = min_array_idx(s, n);
        if (Lp - s[min_idx] >= 0) {
            maxSegm++;
            Lp = Lp - s[min_idx];
            s[min_idx] = -1;
        } else {
            break;
        }
    }

    return maxSegm;
}

//ritorna l'indice del valore minore nell'array
//skippa i -1
int min_array_idx(int *a, int n) {
    int min = a[0];
    int min_idx = 0;

    for (int i=1; i < n; i++) {
        if (a[i] == -1)
            continue;

        if (a[i] < min) {
            min = a[i];
            min_idx = i;
        }
    }
    return min_idx;
}
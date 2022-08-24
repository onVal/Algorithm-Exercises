#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    FILE *input = fopen("POST.IN", "r+");
    
    int n, k;
    int *villages;
    int *somme;
    int *sommeMin;

    fscanf(input, "%d %d\n", &n, &k);

    villages = malloc(n * sizeof(int));
    somme = calloc(n, sizeof(int));
    sommeMin = malloc(k * sizeof(int));

    for (int i=0; i < n; i++) {
        fscanf(input, "%d", &villages[i]);
    }

    fclose(input);

    // ------O(n^2)---------------------------

    int t = k;
    int minSomma = INT_MAX;

    for (int v=0; v < n; v++) {
        for (int i=0; i < n; i++) {
            somme[v] += abs(villages[v] - villages[i]);
        }
    }

    for (int i=0; i < n-1; i++) {
        for (int j=0; j < n-1; j++) {
            if (somme[j] > somme[j+1])
                swap(&somme[j], &somme[j+1]);
        }
    }

    for (int i=0; i < k; i++) {
        printf("%3d ", somme[i]);
    }
}
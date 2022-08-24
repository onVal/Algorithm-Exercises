#include <stdio.h>

int main () {
    int n, fv;
    scanf("%d", &n);

    int l = 0;
    int prev = -1;
    int max = 1;

    for (int i=0; i < n; i++) {
        scanf("%d", &fv);
        if (fv >= prev) {
            l++;
        } else {
            if (l > max) max = l;
            l = 1;        
        }
        prev = fv; 
    }

    if (l > max) max = l;

    printf("%d\n", max);
}
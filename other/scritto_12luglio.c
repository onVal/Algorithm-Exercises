#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int longestSubString(char *s, char *t);

int main() {
    char s[] = "amicizia";
    char t[] = "camicia";
    int l = longestSubString(s, t);

    printf("Max substring = %d\n", l);

    return 0;
}

int longestSubString(char *s, char *t) {
    int s_size = getsize(s);
    int t_size = getsize(t);

    int **Cmatrix = calloc(s_size + 1, sizeof(int *));
    for (int i=0; i < s_size + 1; i++)
        Cmatrix[i] = calloc(t_size + 1, sizeof(int));
    
    for (int i=1; i <= s_size; i++) {
        for (int j=1; j <= t_size; j++) {
            // printf("i-1 = %d and j-1 = %d\n", i-1, j-1);
            if (s[i-1] == t[j-1])
                Cmatrix[i][j] = Cmatrix[i-1][j-1] + 1;
        }
    }

    //prints
     for (int i=0; i < s_size + 1; i++) {
        for (int j=0; j < t_size + 1; j++) {
            printf("%d ", Cmatrix[i][j]);
        }

        printf("\n");
    }

    //finds max
    int max = 0;
    for (int i=0; i < s_size; i++) {
        for (int j=0; j < t_size; j++) {
            if (Cmatrix[i][j] > max)
                max = Cmatrix[i][j];
        }
    }

    return max;
}
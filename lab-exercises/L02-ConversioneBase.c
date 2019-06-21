#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int b, n, temp_n;
    printf("Inserisci un intero b e un numero in base b da convertire in base 10: ");
    scanf("%d%d.", &b, &n);
    temp_n = n;

    int i = 0;
    int result = 0;
    int digit; 

    while(temp_n != 0) {
        digit = temp_n % 10;
        if (digit >= b) {
            printf("Invalid number!");
            exit(1);
        }

        result += digit * pow(b, i);
        i++;
        temp_n /= 10;
    }

    printf("Il numero %d in base %d equivale al numero %d in base 10.", n, b, result);
}
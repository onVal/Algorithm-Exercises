//5 Cifrario di Cesare

#include <stdio.h>
#include <ctype.h>
#define NUM_OF_ALPHA 26

int main(void) {
    int code; 
    int encoded, offset;
    char c;

        scanf("%d", &code);
        code = code % 26;
        
        while ((c=getchar()) != '\n') {
            if (!isalpha(c)) {
                putchar(c);
                continue;
            }

            encoded = c + code;
            
            if ((islower(c) && encoded > 'z') ||
                (isupper(c) && encoded > 'Z'))
                offset = NUM_OF_ALPHA;
            else
                offset = 0;

            putchar(encoded - offset);
        }
    
        printf("\n");

    return 0;
}

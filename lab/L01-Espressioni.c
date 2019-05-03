#include <stdio.h>

int main() {
    int c;
    int chCounter = 0;
    int openCounter, closedCounter;
    openCounter = closedCounter = 0;

    printf("Stringa: ");
    
    while((c = getchar()) != '.') {
        switch (c) {
            case '(':
                ++openCounter;
                break;
            case ')':
                ++closedCounter;
                break;
        }
        ++chCounter;

        if (closedCounter > openCounter)
            break;
    } 

    if (openCounter == closedCounter)
        printf("La stringa é un'espressione ben parentesizzata\n");
    else if (openCounter > closedCounter) {
        printf("La stringa é un'espressione ben parentesizzata:\n");
        printf("Carattere %d: mancano parentesi chiuse alla fine!", chCounter);
    }   
    else {
        printf("La stringa é non un'espressione ben parentesizzata:\n");
        printf("Carattere %d: troppe parentesi chiuse!", chCounter);
    }

    return 0;
}
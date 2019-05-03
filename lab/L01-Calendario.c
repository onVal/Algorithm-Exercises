#include <stdio.h>

int main() {
    int startDay, month;

    printf("Inserisci il numero del mese (1 = gennaio, ..., 12 = dicembre): ");
    scanf("%d", &month);

    printf("Inserisci il giorno in inizio mese (1 = lunedi, ..., 7 = domenica): ");
    scanf("%d", &startDay);

    int daysPerMonth;

    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            daysPerMonth = 31;
            break;
        case 2:
            daysPerMonth = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysPerMonth = 30;
            break;
        default:
            printf("Invalid month!\n");
            return 1;
    }

    printf("%-5c%-5c%-5c%-5c%-5c%-5c%-5c\n", 'L', 'M', 'M', 'G', 'V', 'S', 'D'); 
        int i;
        for (i=1; i < startDay; i++) {
            printf("%-5c", ' ');
    }

    for (i=1; i <= daysPerMonth; i++) {
        printf("%-5d", i);
        if ((startDay+i) % 7 == 1) printf("\n");
    }

    printf("\n");

    return 0;
}
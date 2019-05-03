#include <stdio.h>
typedef struct {
    char nome[50];
    char numero[12];
} Contatto;

void printMenu() {
    printf("RUBRICA\n");
    printf("Clicca 1 per inserire un nuovo contatto\n");
    printf("Clicca 2 per visualizzare i tuoi contatti\n");
    printf("Clicca 0 per uscire\n");
}

int main() {
    int i, selection, latest_index = 0;
    Contatto contatto, rubrica[200];

    do {
        printMenu();
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                printf("Inserisci nome e numero: ");
                scanf("%50s%10s", contatto.nome, contatto.numero);
                rubrica[latest_index] = contatto;
                latest_index++;
                break;
            case 2:
                printf("%12s%10s\n", "Nome", "Numero");
                
                for (i=0; i < latest_index; i++) {
                    printf("%2d %10s %10s\n", i, rubrica[i].nome, rubrica[i].numero);
                }
                break;
            case 0:
                printf("Goodbye!\n");  
                return 1;
                break;  
        }
    } while(1);
}

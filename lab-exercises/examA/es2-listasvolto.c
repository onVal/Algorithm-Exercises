/*
1. La build crea un nodo in coda alla lista.
a) Ritorna flist (del nodo) che e' una funzione ricorsiva
    la quale ritorna una lista di nodi linkati che contengono
    una porzione della stringa w ciascuna

b) lunghezza di w volte
c) di essere arrivati all'ultimo carattere della stringa (prima di \0)
d) viene passato il puntatore alla stringa incrementato di 1, ovvero
    che punta al carattere successivo

2. fstring concatena w con le stringhe rappresentate dentro la nostra lista di Node
    w deve avere abbastanza spazio allocato da poter occupare le stringhe concatenate
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    char *w;
    struct node *next;
} *Node;

char *fstring( char *w, Node l ){
	if ( l -> next == NULL )
		return strcat( w, l -> w );

	return strcat( fstring( w, l -> next ), l -> w );
}
 
char *fstring_iter(char *w, Node l) {
    Node t = l;

    while (t->next != NULL) {
        t=t->next;
    }

    int size = strlen(t->w);
    int i = strlen(w);

    for (int x=0; x < size; ++x) {
        for (int j=x; j < size; ++j) {
            w[i] = t->w[j];
            i++; 
        }
    }
    
    return w;
}

Node flist( Node l ) {
	if (l->w[0] != '\0' && l->w[1] == '\0')
		return l;
	Node n = malloc(sizeof(struct node));
	n -> w = ( l -> w ) + 1;
	n -> next = l;
	return flist( n );		
}

Node flist2(Node l) {
    int len;
    if ((len=strlen(l->w)) == 1)
		return l;

	Node n = malloc(sizeof(struct node));
    n->w = malloc(len);
    strncpy(n->w, l->w, len-1);
	n->next = l;
	return flist2(n);
}

Node build( char *w ) {
	Node lista = malloc (sizeof(struct node) );
	lista -> w = w;
	lista -> next = NULL;
	return flist2( lista );
}

// o - lo - llo - ello - Hello
// h - he - hel - Hell - Hello



int main() {
    char word[20];
    printf("%s\n", fstring(word, build("hello")));
    
    // char parola[20] = "";
    // printf("%s\n", fstring_iter(parola, build("hello")));

    return 0;
}


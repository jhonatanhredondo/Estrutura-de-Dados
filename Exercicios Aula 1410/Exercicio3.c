#include <stdio.h>

typedef struct No {
    int info; 
    struct No *prox;
} *Lista; 


void inserir(Lista p, int x) {
    Lista novo;
    novo = malloc(sizeof(Lista));
    novo->info = x;
    novo->prox = p->prox;
    p->prox = novo;
}


Lista *CopiaInversa(Lista ponteiro) {
    Lista Copia = malloc(sizeof(Lista));
    Copia->prox = NULL;
    Lista ponteiroCopia = Copia;
    ponteiro = ponteiro->prox;
    while(ponteiro) {
        inserir(ponteiroCopia, ponteiro->info);
        ponteiro = ponteiro->prox;
        ponteiroCopia = Copia; 
    }   
    return Copia;
}


void imprimeLista(Lista ini) { //pode passar o No *ponteiro; 
    Lista p = ini->prox; 
    while(p) {
        printf("%d ", p->info);
        p = p->prox;
    }
}


main() 
{
    Lista ponteiroListaOriginal = malloc(sizeof(Lista));
    ponteiroListaOriginal->prox = NULL;
    inserir(ponteiroListaOriginal, 1);
    inserir(ponteiroListaOriginal, 2);
    inserir(ponteiroListaOriginal, 3);
    inserir(ponteiroListaOriginal, 4);
    printf("Lista Original: ");
    imprimeLista(ponteiroListaOriginal);
    Lista ponteiroCopia = CopiaInversa(ponteiroListaOriginal);
    printf("\nLista Copia: ");
    imprimeLista(ponteiroCopia);
}
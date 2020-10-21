#include <stdio.h>

typedef struct No {
    struct No *prox;
    int info;
} *Lista; 


void remove_todos(Lista inicio, int valor) {
    Lista p = inicio->prox; 
    Lista q = inicio; 
    while (p) {
        if(p->info == valor) {
            remover(q);
            p = q->prox;
        } else {
            p = p->prox;
            q = q->prox;
        }
    }
}

Lista *Copia(Lista ponteiro) {
    Lista Copia = malloc(sizeof(Lista)); 
    Copia->prox = NULL;
    Lista ponteiroCopia = Copia;
    ponteiro = ponteiro->prox;
    int x;
    while (ponteiro) {
        inserir(ponteiroCopia, ponteiro->info);
        ponteiroCopia = ponteiroCopia->prox;
        ponteiro = ponteiro->prox;
    }
    return Copia;
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


void remover(Lista ini) {
    Lista aux; 
    aux = ini->prox;
    ini->prox = aux->prox;
    free(aux);
}


void inserir(Lista p, int x) {
    Lista novo;
    novo = malloc(sizeof(Lista));
    novo->info = x;
    novo->prox = p->prox;
    p->prox = novo;
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
    Lista inicio = malloc(sizeof(Lista));
    inicio->prox = NULL;
    int valores; 
    inserir(inicio, 2);
    inserir(inicio, 3);
    inserir(inicio, 2);
    inserir(inicio, 2);
    inserir(inicio, 1);
    inserir(inicio, 4);
    inserir(inicio, 2);
    inserir(inicio, 5);
    printf("Lista Original: ");
    imprimeLista(inicio);
    remove_todos(inicio, 2);
    printf("\nLista sem Repetir: ");
    imprimeLista(inicio);
    //Exercicio 2;
    Lista ponteiroCopia = Copia(inicio);
    printf("\nLista Copia: ");
    imprimeLista(ponteiroCopia);
    Lista ponteiroCopiaInvertida = CopiaInversa(inicio);
    printf("\nLista Inversa: ");
    imprimeLista(ponteiroCopiaInvertida);
}   
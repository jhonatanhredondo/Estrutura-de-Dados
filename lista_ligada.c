#include <stdio.h>
#include <stdlib.h>

//lista com cabeça

typedef struct No {
    int info; 
    struct No *prox;
} No, *Lista; 


void imprimeLista(Lista ini) { //pode passar o No *ponteiro; 
    No *p = ini->prox; 
    while(p) {
        printf("%d ", p->info);
        p = p->prox;
    }
}

void imprimeRecursiva(No *ini) {
    if(ini->prox) {
        imprimeRecursiva(ini->prox);
        printf("%d ", ini->info);
    }
}

No *busca(No *ini, int x) {
    No *p = ini->prox; 
    while(p && p->info != x) {
        p = p->prox;
    }
    return p;
}

No *buscaRecursiva(Lista ini, int x) {
    if(!ini->prox || ini->info == x) {
        return ini->prox;
    }
    return buscaRecursiva(ini->prox, x);
}


void insere(No *p, int x) {
    No *novo;
    novo = malloc(sizeof(Lista));
    novo->info = x;
    novo->prox = p->prox;
    p->prox = novo;
}

No *insereInicio(No *ini, int x) {
    No *novo; 
    novo = malloc(sizeof(No));
    novo->info = x;
    novo->prox = ini;
    return novo; 
}

void insereInicioAlternativa(No **ini, int x) {
    No *novo; 
    novo = malloc(sizeof(No));
    novo->info = x;
    novo->prox = *ini;
    *ini = novo;
}
/*
void remove(Lista *ini) {
    No *aux; 
    aux = ini->prox;
    ini->prox = aux->prox;
    free(aux);
}
*/

main()
{
    Lista ini; 
    ini = malloc(sizeof(Lista));
    ini->prox = NULL;
    insere(ini, 1);
    insere(ini, 2);
    imprimeLista(ini);
    remove(ini);
}
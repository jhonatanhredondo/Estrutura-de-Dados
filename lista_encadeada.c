#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info; 
    struct No *prox;
} No, *Lista; 

Lista p;
No *ponteiro; 

void imprimeLista(Lista ini) { //pode passar o No *ponteiro; 
    No *p = ini; 
    while(p) {
        printf("%d ", p->info);
        p = p->prox;
    }
}

void imprimeRecursiva(No *ini) {
    if(ini) {
        imprimeRecursiva(ini->prox);
        printf("%d ", ini->info);
    }
}

No *busca(No *ini, int x) {
    No *p = ini; 
    while(p && p->info != x) {
        p = p->prox;
    }
    return p;
}

No *buscaRecursiva(Lista ini, int x) {
    if(!ini || ini->info == x) {
        return ini;
    }
    return buscaRecursiva(ini->prox, x);
}


void insereMeio(Lista ini, int x) {
    Lista novo;
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

void remove(No *p) {
    No *aux; 
    aux = p->prox;
    p->prox = aux->prox;
    free(aux);
}

main()
{
    No a;
    p = &a;
    a.info = 1;
    a.prox = NULL; 
    No b; 
    b.info = 2; 
    a.prox = &b; 
    b.prox = NULL;
    ponteiro = &a;
    imprimeLista(p);
    printf("\n");
    imprimeRecursiva(ponteiro);
    Lista posicao = busca(p, 2);
    printf("\nPosicao: %d", posicao->info);
    No *posicaoRec = buscaRecursiva(ponteiro, 1);
    printf("\nPosicao Rec: %d\n", posicaoRec->info);
    insereMeio(p, 3);
    imprimeLista(p);
    printf("\n");
    p = insereInicio(p, 4);
    imprimeLista(p);
    printf("\n");
    insereInicioAlternativa(&p, 5);
    imprimeLista(p);
}
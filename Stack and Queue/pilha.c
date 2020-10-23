#include <stdio.h>
#include <stdlib.h>
#define TAMPILHA 100

struct pilha {
    int topo; 
    int listapilha[TAMPILHA];
};

int empty(struct pilha *pilha) 
{
    if (pilha->topo == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct pilha *pilha, int x)
{
    if (pilha->topo == TAMPILHA - 1) {
        printf("Stack OverFlow\n");
        exit(1);
    }
    else pilha->listapilha[++(pilha->topo)] = x;
}

int pop(struct pilha *pilha) 
{
    if(empty(pilha)) {
        printf("Stack UnderFlow\n");
        exit(1);
    }
    else return (pilha->listapilha[pilha->topo--]);
}

main()
{
    struct pilha pilha;
    pilha.topo = -1;
    if(empty(&pilha)) {
        printf("%s", "Pilha Vazia!\n");
    }
    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);
    push(&pilha, 4);
    printf("%d ", pop(&pilha));
    printf("%d ", pop(&pilha));
    printf("%d ", pop(&pilha));
    printf("%d\n", pop(&pilha));
    printf("%d ", pop(&pilha));
}
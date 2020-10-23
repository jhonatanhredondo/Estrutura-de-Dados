#include <stdlib.h>
#include <stdio.h>
#define MAXFILA 100

struct fila {
    int items[MAXFILA];
    int front, rear; 
};

int empty(struct fila *fila) {
    if (fila->front == -1) return 1;
    else return 0;
}

void push(struct fila *fila, int x) {
    if (fila->front == (MAXFILA - 1)) {
        printf("Queue OverFlow\n");
        exit(1);
    } else fila->items[++fila->front] = x;
}

int pop(struct fila *fila) {
    if(empty(fila)) {
        printf("Queue UnderFlow\n");
        exit(1);
    } else {
        int y = fila->items[fila->rear];
        while(fila->rear < fila->front) {
            fila->items[fila->rear] = fila->items[++fila->rear];
        }
        fila->front--;
        fila->rear = 0;
        return y;
    }
}

main() 
{
    struct fila fila;
    fila.front = -1;
    fila.rear = 0;
    if (empty(&fila)) printf("Fila Vazia\n");
    push(&fila, 1);
    push(&fila, 2);
    push(&fila, 3);
    push(&fila, 4);
    printf("%d ", pop(&fila));
    printf("%d ", pop(&fila));
    printf("%d ", pop(&fila));
    printf("%d\n", pop(&fila));
    printf("%d ", pop(&fila));
}

//sei que não precisava entregar, mas entreguei caso ache algum erro!
#include <stdio.h>
#include <stdlib.h>
#define TAMSTACK 100

typedef struct {
    int lista[TAMSTACK];
    int top;
} Stack;

int empty(Stack *stack) {
    if(stack->top == -1) return 1;
    else return 0;
}

void push(Stack *stack, int valueAdded) {
    if(stack->lista[stack->top] == TAMSTACK-1) {
        printf("Stack OverFlow \n");
        exit(0);
    } else {
        stack->lista[++stack->top] = valueAdded;
    }
}

int pop(Stack *stack) {
    if(stack->top == -1) {
        printf("Stack UnderFlow\n");
        exit(1);
    } else {
        return stack->lista[stack->top--];
    }
}

main() 
{
    Stack stack;
    stack.top = -1;
    if(empty(&stack)) printf("Lista Vazia\n");
    push(&stack, 1);
    push(&stack, 10);
    push(&stack, 100);
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d", pop(&stack));
}
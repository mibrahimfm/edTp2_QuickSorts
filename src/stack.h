#include <stdlib.h>

//Definindo umma struct Pair para utilizar na pilha
struct Pair{
    int left;
    int right;
};

//Definindo a pilha para implementação do QuickSort não recursivo
struct Stack{
    int top;
    unsigned size;
    struct Pair* array;
};

//Cria pilha vazia com tamanho 'capacity'
struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = capacity;
    stack->top = -1;
    stack->array = (struct Pair*) malloc(stack->size * sizeof(struct Pair));
    return stack;
};

int isFull(struct Stack* stack){return stack->top == stack->size - 1;}

int isEmpty(struct Stack* stack){return stack->top == - 1;}

//Insert novo elemento do tipo Pair na pilha
void insert(struct Stack* stack, struct Pair item){
    if(isFull(stack))
        return;
    stack->array[stack->top++] = item;
}

//Remove o elemento do topo da pilha
int pop(struct Stack* stack, struct Pair* item){
    if(isEmpty(stack))
        return 0;
    *item = stack->array[--stack->top];
    return 1;
}
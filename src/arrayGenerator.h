#include <stdlib.h>

//Cria um array de tamanho 'size' aleatório com elementos int no intervalo [1, size]
int* randomGenerator(int size){
    int *arr = (int *)malloc (size * sizeof(int));
    int i = 0;
    for(; i < size; i++){
        arr[i] = rand() % size + 1 ;
    }
    return arr;
}

//Cria um array de tamanho 'size' crescente com os elementos do intervalo[1, size]
int* ascendingGenerator(int size){
    int *arr = (int *)malloc (size * sizeof(int));
    int i = 0;
    for(; i < size; i++){
        arr[i] = i + 1;
    }
    return arr;
}

//Cria um array de tamanho 'size' decrescente com os elementos do intervalo[1, size]
int* descendingGenerator(int size){
    int *arr = (int *)malloc (size * sizeof(int));
    int i = 0, helper = size;
    for(; i < size; i++){
        arr[i] = helper--;
    }
    return arr;
}
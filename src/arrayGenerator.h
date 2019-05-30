#include <stdlib.h>

int* randomGenerator(int size){
    int *arr = (int *)malloc (size * sizeof(int));
    int i = 0;
    for(; i < size; i++){
        arr[i] = rand() % size + 1;
    }
    return arr;
}

int* ascendingGenerator(int size){
    int *arr = (int *)malloc (size * sizeof(int));
    int i = 0;
    for(; i < size; i++){
        arr[i] = i + 1;
    }
    return arr;
}

int* descendingGenerator(int size){
    int *arr = (int *)malloc (size * sizeof(int));
    int i = 0, helper = size;
    for(; i < size; i++){
        arr[i] = helper;
        helper--;
    }
    return arr;
}
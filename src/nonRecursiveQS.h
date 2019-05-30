#include "classicQS.h"
#include "stack.h"
#include <stdio.h>

void NonRecursiveQuickSort(int* A, int n){
    struct Stack* stack = createStack(n);
    struct Pair item;
    int left, right, i, j;
    isEmpty(stack);
    left = 0;
    right = n-1;
    item.right = right;
    item.left = left;
    insert(stack, item);

    do{
        if(right > left){
            ClassicPartition(left, right, &i, &j, A);
            if((j - left) > (right - i)){
                item.right = j;
                item.left = left;
                insert(stack, item);
                left = i;
            }
            else{
                item.left = i;
                item.right = right;
                insert(stack, item);
                right = j;
            }
        }
        else{
            pop(stack, &item);
            right = item.right;
            left = item.left;
        }
    }
    while(!isEmpty(stack));
}
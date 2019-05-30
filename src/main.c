#include <stdio.h>
#include <stdlib.h>
#include "classicQS.h"
#include "medianQS.h"
#include "firstElQS.h"
#include "insert1QS.h"
#include "insert5QS.h"
#include "insert10QS.h"
#include "nonRecursiveQS.h"
#include "arrayGenerator.h"

int main(int argc, char** argv){
    int i, j, k;
    int *A = descendingGenerator(50);
    // int B[11] = {3,84,21,62,1,48,0,-52,33,155,11};
    // int C[8] = {3,15,15,44,0,-12,155,11};

    ClassicQuickSort(A, 50);
    //MedianQuickSort(B, 11);
    // FirstElQuickSort(C, 8);
    //Insert1QuickSort(C, 8);
    //Insert5QuickSort(C, 8);
    //Insert10QuickSort(B, 11);
    //NonRecursiveQuickSort(A, 50);
    // NonRecursiveQuickSort(B, 11);
    // NonRecursiveQuickSort(C, 8);

    for(i = 0; i < 50; i++)
        printf("%d\n", A[i]);
    printf("\n");
    // for(j = 0; j < 11; j++)
    //     printf("%d\n", B[j]);
    // printf("\n");
    // for(k = 0; k < 8; k++)
    //     printf("%d\n", C[k]);
}
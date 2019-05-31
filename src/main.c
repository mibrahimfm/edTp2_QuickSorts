#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int *A;
    int size = atoi(argv[3]);
    if(strcmp(argv[2], "Ale") == 0)
        A = randomGenerator(size);
    else if(strcmp(argv[2],"OrdC")  == 0)
        A = ascendingGenerator(size);
    else if(strcmp(argv[2], "OrdD") == 0)
        A = descendingGenerator(size);

    if(strcmp(argv[1], "QC") == 0)
        ClassicQuickSort(A, size);
    else if(strcmp(argv[1], "QM3") == 0)
        MedianQuickSort(A, size);
    else if(strcmp(argv[1], "QPE") == 0)
        FirstElQuickSort(A, size);        
    else if(strcmp(argv[1], "QI1") == 0)
        Insert1QuickSort(A, size);
    else if(strcmp(argv[1], "QI5") == 0)
        Insert5QuickSort(A, size);
    else if(strcmp(argv[1], "QI10") == 0)
        Insert10QuickSort(A, size);
    else if(strcmp(argv[1], "QNR") == 0)
        NonRecursiveQuickSort(A, size);

    for(i = 0; i < size; i++)
        printf("%d\n", A[i]);
    printf("\n");
}
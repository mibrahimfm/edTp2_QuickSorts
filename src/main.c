#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "classicQS.h"
#include "medianQS.h"
#include "firstElQS.h"
#include "insert1QS.h"
#include "insert5QS.h"
#include "insert10QS.h"
#include "nonRecursiveQS.h"
#include "arrayGenerator.h"

int main(int argc, char** argv){
    //declarando variáveis necessárias para o progrma
    int i, k;
    int *arr;
    char* variation = argv[1];
    char* arrayType = argv[2];
    int size = atoi(argv[3]);//convertendo o parâmetro para inteiro

    //definindo qual array gerar: Aleatório, crescente ou decrescente
    if(strcmp(arrayType, "Ale") == 0)
        arr = randomGenerator(size);
    else if(strcmp(arrayType,"OrdC")  == 0)
        arr = ascendingGenerator(size);
    else if(strcmp(arrayType, "OrdD") == 0)
        arr = descendingGenerator(size);

    //definindo o tipo do QuickSort a ser chamado
    if(strcmp(variation, "QC") == 0)
        ClassicQuickSort(arr, size);
    else if(strcmp(variation, "QM3") == 0)
        MedianQuickSort(arr, size);
    else if(strcmp(variation, "QPE") == 0)
        FirstElQuickSort(arr, size);        
    else if(strcmp(variation, "QI1") == 0)
        Insert1QuickSort(arr, size);
    else if(strcmp(variation, "QI5") == 0)
        Insert5QuickSort(arr, size);
    else if(strcmp(variation, "QI10") == 0)
        Insert10QuickSort(arr, size);
    else if(strcmp(variation, "QNR") == 0)
        NonRecursiveQuickSort(arr, size);

    //imprimindo resultados
    printf("%s %s %d\n", variation, arrayType, size);
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
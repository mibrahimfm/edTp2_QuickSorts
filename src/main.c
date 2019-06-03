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
    int i, j = 0, testRepeting = 0, allocator = 0;
    int *arr;
    char* variation = argv[1];
    char* arrayType = argv[2];
    int size = atoi(argv[3]);//convertendo o parâmetro para inteiro
    int **results = malloc(size*sizeof(int*));  //allocate memory to double pointer
    for (; allocator < size; allocator++){
        results[allocator] = malloc(20*sizeof(int*));
    }

    printf("%s %s %d\n", variation, arrayType, size);


    for(; testRepeting < 20; testRepeting++, j++){
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

    
        //alocando resultados para imprimir os vetores ordenados após os cálculos de tempo, ordenacoes, etc.
        for(i = 0; i < size; i++){
            results[i][j] = arr[i];
        }

        //desalocando vetor utilizado antes de repetir o teste para evitar memory leak
        free(arr);
    }
    for(i = 0; i < 20; i++){
        for(j = 0; j < size; j++)
            printf("%d ", results[j][i]);
        printf("\n");
    }

    //desalocando o vetor results
    free(results);

}
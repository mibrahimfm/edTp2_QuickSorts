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
    int i, j = 0, testRepeating = 0, allocator = 0;
    unsigned long long int comparisonCounter = 0, movementCounter = 0;
    int *arr;
    char* variation = argv[1];
    char* arrayType = argv[2];
    int size = atoi(argv[3]);//convertendo o parâmetro para inteiro
    char* optional = argv[4] != NULL ? argv[4] : " ";
    int **results;
    double *times = (double*) malloc (20 * sizeof(double));
    double time_spent;

    //double pointer utilizado para imprimir vetores com passagem de parâmetro -p
    if(strcmp(optional, "-p") == 0){
	results = malloc(size*sizeof(int*));        
	for (; allocator < size; allocator++)                       //double;
            results[allocator] = malloc(20*sizeof(int));  //pointer
    }


    for(; testRepeating < 20; testRepeating++, j++){
        //definindo qual array gerar: Aleatório, crescente ou decrescente
        if(strcmp(arrayType, "Ale") == 0)
            arr = randomGenerator(size);
        else if(strcmp(arrayType,"OrdC")  == 0)
            arr = ascendingGenerator(size);
        else if(strcmp(arrayType, "OrdD") == 0)
            arr = descendingGenerator(size);


        //alocando resultados para imprimir os vetores ordenados após os cálculos de tempo, ordenacoes, etc.
        if(strcmp(optional, "-p") == 0){
            for(i = 0; i < size; i++){
                results[i][testRepeating] = arr[i];
            }
        }


        //começa a cronometrar o tempo do QS
        clock_t begin = clock();
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

        clock_t end = clock();
        times[testRepeating] = (double)(end - begin) / CLOCKS_PER_SEC;

        //desalocando vetor utilizado antes de repetir o teste para evitar memory leak
        free(arr);
    }    

    time_spent = (times[9] + times[10]) / 2.0;
    time_spent *= 1000000;

    //Calculando a média de comparações e movimentos em cada QS
    if(strcmp(variation, "QC") == 0){
        comparisonCounter = classicCC / 20; movementCounter = classicMC/20;
    }
    else if(strcmp(variation, "QM3") == 0){
        comparisonCounter = medianCC / 20; movementCounter = medianMC/20;
    }
    else if(strcmp(variation, "QPE") == 0){
        comparisonCounter = firstCC / 20; movementCounter = firstMC/20;
    }   
    else if(strcmp(variation, "QI1") == 0){
        comparisonCounter = insertCC / 20; movementCounter = insertMC/20;
    }
    else if(strcmp(variation, "QI5") == 0){
        comparisonCounter = insertCC / 20; movementCounter = insertMC/20;
    }
    else if(strcmp(variation, "QI10") == 0){
        comparisonCounter = insertCC / 20; movementCounter = insertMC/20;
    }
    else if(strcmp(variation, "QNR") == 0){
        comparisonCounter = classicCC / 20; movementCounter = classicMC/20;
    }


    printf("%s %s %d %llu %llu %0.f\n", variation, arrayType, size, comparisonCounter, movementCounter, time_spent);
    

    if(strcmp(optional, "-p") == 0){
        for(i = 0; i < 20; i++){
            for(j = 0; j < size; j++)
                printf("%d ", results[j][i]);
            printf("\n");
        }

        //desalocando o vetor results
        free(results);
    }
}
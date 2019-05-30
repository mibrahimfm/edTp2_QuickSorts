#include "insert1QS.h"

void Insert5Sorting(int Esq, int Dir, int *A, int tamanho) {
    int i, j, middle;
    InsertPartition(Esq, Dir, &middle, &i, &j, A);
    if(Dir <= 0.05 * tamanho)
        insertionSort(A, Esq, Dir);
    if (Esq < j)
        Insert1Sorting(Esq, j, A, tamanho);
    if (i < Dir)
        Insert1Sorting(i, Dir, A, tamanho);
}

void Insert5QuickSort(int *A, int n) {
    Insert5Sorting(0, n-1, A, n);
}
#include "insert1QS.h"

void Insert5Sorting(int left, int right, int *arr, int size) {
    int i, j, middle;
    InsertPartition(left, right, &middle, &i, &j, arr);
    
    //Condição de parada para usar InsertSort ao invés de QuickSort
    if(right <= 0.05 * size)
        insertionSort(left, right, arr);
    if (left < j)
        Insert1Sorting(left, j, arr, size);
    if (i < right)
        Insert1Sorting(i, right, arr, size);
}

void Insert5QuickSort(int *arr, int n) {
    Insert5Sorting(0, n-1, arr, n);
}
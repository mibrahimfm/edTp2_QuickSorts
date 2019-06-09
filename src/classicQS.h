#ifndef CLASSIC_H
#define CLASSIC_H

static int classicCC = 0;
static int classicMC = 0;

void ClassicPartition(int left, int right, int *i, int *j, int *arr) {
    int pivot, aux; 
    *i = left;
    *j = right;
    //pivô como elemento central
    pivot = arr[(*i + *j)/2];
    do {
        while (pivot > arr[*i]){
            classicCC++;
            (*i)++;
        }
        while (pivot < arr[*j]){
            classicCC++;
            (*j)--;
        }
        if (*i <= *j) {
            if (*i < *j){ 
                 classicCC++;           
                 classicMC++;
            }
            aux = arr[*i];
            arr[*i] = arr[*j];
            arr[*j] = aux;
            (*i)++; (*j)--;
        }
    }
    while (*i <= *j);
}

void ClassicSorting(int left, int right, int *arr) {
    int i, j;
    ClassicPartition(left, right, &i, &j, arr);
    if (left < j)
        ClassicSorting(left, j, arr);
        if (i < right)
            ClassicSorting(i, right, arr);
    }
void ClassicQuickSort(int *arr, int n) {
    ClassicSorting(0, n-1, arr);
}

#endif
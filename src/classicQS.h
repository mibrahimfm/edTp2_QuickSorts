#ifndef CLASSIC_H
#define CLASSIC_H

void ClassicPartition(int left, int right, int *i, int *j, int *arr) {
    int pivot, aux; 
    *i = left;
    *j = right;
    //pivô como elemento central
    pivot = arr[(*i + *j)/2];
    do {
        while (pivot > arr[*i])
            (*i)++;
        while (pivot < arr[*j])
            (*j)--;
        if (*i <= *j) {
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
#ifndef CLASSIC_H
#define CLASSIC_H

void ClassicPartition(int Esq, int Dir, int *i, int *j, int *A) {
    int x, w; 
    *i = Esq;
    *j = Dir;
    x = A[*i];
    do {
        while (x > A[*i])
            (*i)++;
        while (x < A[*j])
            (*j)--;
        if (*i <= *j) {
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++; (*j)--;
        }
    }
    while (*i <= *j);
}

void ClassicSorting(int Esq, int Dir, int *A) {
    int i, j;
    ClassicPartition(Esq, Dir, &i, &j, A);
    if (Esq < j)
        ClassicSorting(Esq, j, A);
        if (i < Dir)
            ClassicSorting(i, Dir, A);
    }
void ClassicQuickSort(int *A, int n) {
    ClassicSorting(0, n-1, A);
}

#endif
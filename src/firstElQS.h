void FirstElPartition(int Esq, int Dir, int *i, int *j, int *A) {
    int x, w; 
    *i = Esq;
    *j = Dir;
    x = A[(*i + *j)/2];
    /* obtem o pivo x */
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

void FirstElSorting(int Esq, int Dir, int *A) {
    int i, j;
    FirstElPartition(Esq, Dir, &i, &j, A);
    if (Esq < j)
        FirstElSorting(Esq, j, A);
        if (i < Dir)
            FirstElSorting(i, Dir, A);
    }
void FirstElQuickSort(int *A, int n) {
    FirstElSorting(0, n-1, A);
}
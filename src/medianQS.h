void MedianPartition(int Esq, int Dir, int *middle, int *i, int *j, int *A) {
    int x, w; 
    *i = Esq;
    *j = Dir;
    *middle = (*i + *j)/2;
    if(A[*i] > A[*j]){
        if(A[*i] < A[*middle])
            x = A[*i];
        else{
            if(A[*middle] > A[*j])
                x = A[*middle];
            else
                x = A[*j];
        }
    }
    else{
        if(A[*j] < A[*middle])
            x = A[*j];
        else{
            if(A[*middle] > A[*i])
                x = A[*middle];
            else
                x = A[*i];
        }
    }
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

void MedianSorting(int Esq, int Dir, int *A) {
    int i, j, middle;
    MedianPartition(Esq, Dir,&middle, &i, &j, A);
    if (Esq < j)
        MedianSorting(Esq, j, A);
        if (i < Dir)
            MedianSorting(i, Dir, A);
    }

void MedianQuickSort(int *A, int n) {
    MedianSorting(0, n-1, A);
}
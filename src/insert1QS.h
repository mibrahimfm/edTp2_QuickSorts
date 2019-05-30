#ifndef  INSERT_H
#define INSERT_H

void insertionSort(int *v, int left, int right) { 
    int i = left, key, j; 
    for (; i <  right; i++) { 
        key = v[i]; 
        j = i - 1; 

        while (j >= 0 && v[j] > key) { 
            v[j + 1] = v[j]; 
            j = j - 1; 
        } 
        v[j + 1] = key; 
    } 
}

void InsertPartition(int Esq, int Dir,int *middle, int *i, int *j, int *A) {
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

void Insert1Sorting(int Esq, int Dir, int *A, int tamanho) {
    int i, j, middle;
    InsertPartition(Esq, Dir,&middle, &i, &j, A);
    if(Dir <= 0.01 * tamanho)
        insertionSort(A, Esq, Dir);
    if (Esq < j)
        Insert1Sorting(Esq, j, A, tamanho);
    if (i < Dir)
        Insert1Sorting(i, Dir, A, tamanho);
}

void Insert1QuickSort(int *A, int n) {
    Insert1Sorting(0, n-1, A, n);
}

#endif
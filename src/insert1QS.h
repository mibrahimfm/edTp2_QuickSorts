#ifndef  INSERT_H
#define INSERT_H

//definição do método de ordenação por inserção
void insertionSort(int left, int right, int *arr) { 
    int i = left, key, j; 
    for (; i <  right; i++) { 
        key = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

void InsertPartition(int left, int right,int *middle, int *i, int *j, int *arr) {
    int x, w; 
    *i = left;
    *j = right;
    *middle = (*i + *j)/2;
    //definindo pivô como mediana de três
    if(arr[*i] > arr[*j]){
        if(arr[*i] < arr[*middle])
            x = arr[*i];
        else{
            if(arr[*middle] > arr[*j])
                x = arr[*middle];
            else
                x = arr[*j];
        }
    }
    else{
        if(arr[*j] < arr[*middle])
            x = arr[*j];
        else{
            if(arr[*middle] > arr[*i])
                x = arr[*middle];
            else
                x = arr[*i];
        }
    }
    do {
        while (x > arr[*i])
            (*i)++;
        while (x < arr[*j])
            (*j)--;
        if (*i <= *j) {
            w = arr[*i];
            arr[*i] = arr[*j];
            arr[*j] = w;
            (*i)++; (*j)--;
        }
    }
    while (*i <= *j);
}

void Insert1Sorting(int left, int right, int *arr, int size) {
    int i, j, middle;
    InsertPartition(left, right,&middle, &i, &j, arr);
    //Condição de parada para usar InsertSort ao invés de QuickSort
    if(right <= 0.01 * size)
        insertionSort(left, right, arr);
    if (left < j)
        Insert1Sorting(left, j, arr, size);
    if (i < right)
        Insert1Sorting(i, right, arr, size);
}

void Insert1QuickSort(int *arr, int n) {
    Insert1Sorting(0, n-1, arr, n);
}

#endif
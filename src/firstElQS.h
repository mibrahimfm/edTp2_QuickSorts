void FirstElPartition(int left, int right, int *i, int *j, int *arr) {
    int x, w; 
    *i = left;
    *j = right;
    //pivo como primeiro elemento
    x = arr[*i];
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

void FirstElSorting(int left, int right, int *arr) {
    int i, j;
    FirstElPartition(left, right, &i, &j, arr);
    if (left < j)
        FirstElSorting(left, j, arr);
        if (i < right)
            FirstElSorting(i,right, arr);
}

void FirstElQuickSort(int *arr, int n) {
    FirstElSorting(0, n-1, arr);
}
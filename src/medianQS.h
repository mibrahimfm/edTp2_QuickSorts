
static int medianCC = 0;
static int medianMC = 0; 

void MedianPartition(int left, int right, int *middle, int *i, int *j, int *arr) {
    int x, w; 
    *i = left;
    *j = right;
    *middle = (*i + *j)/2;

    //Definindo o pivô como mediana de três
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
        while (x > arr[*i]){
            medianCC++;
            (*i)++;
        }
        while (x < arr[*j]){
            medianCC++;
            (*j)--;
        }
        if (*i <= *j) {
            medianCC++; medianMC++;
            w = arr[*i];
            arr[*i] = arr[*j];
            arr[*j] = w;
            (*i)++; (*j)--;
        }
    }
    while (*i <= *j);
}

void MedianSorting(int left, int right, int *arr) {
    int i, j, middle;
    MedianPartition(left, right,&middle, &i, &j, arr);
    if (left < j)
        MedianSorting(left, j, arr);
    if (i < right)
        MedianSorting(i, right, arr);
    }

void MedianQuickSort(int *arr, int n) {
    MedianSorting(0, n-1, arr);
}
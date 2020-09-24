void quicksort(int a[], int r, int q);

/**
* partition the array into 2 parts and a pivot p
* a[r..p-1] <= a[p] < a[p+1...q]
* return p
*/
int partition(int a[], int r, int q);

/**
* choosing a pivot randomly
* return index of choosing
*/
int randomPivot(int a[], int r, int q);

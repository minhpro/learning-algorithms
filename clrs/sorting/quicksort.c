#include "quicksort.h"
#include "../array/array_utils.h"
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int r, int q) {
    if (r < q) {
        int p = partition(a, r, q);
        quicksort(a, r, p - 1);
        quicksort(a, p + 1, q);
    }
}

/**
* partition the array into 2 parts and a pivot p
* a[r..p-1] <= a[p] < a[p+1...q]
* return p
*/
int partition(int a[], int r, int q) {
    int pivot_index_init = randomPivot(a, r, q);
    int pivot = a[pivot_index_init];
    int current_greater_index = q + 1;
    int i = r;
    // invariant: a[...i-1] <= pivot < a[current_greater_index...]
    while (current_greater_index > i) {
        if (a[i] > pivot) {
            current_greater_index--;
            exchange(a, i, current_greater_index);
        } else {
            i++;
        }
    }
    int pivot_index = current_greater_index - 1;
    exchange(a, pivot_index_init, pivot_index);
    return pivot_index;
}

/**
* choosing a pivot randomly
* return index of choosing
*/
int randomPivot(int a[], int r, int q) {
    int size = q - r + 1;
    // Use current time as seed for random generator 
    srand(time(0));

    return r + (rand() % size);
}

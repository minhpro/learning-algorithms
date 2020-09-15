#include <stdio.h>
#include "../array/array_utils.h"

void insertionSort(int a[], int len) {
    for (int j = 1; j < len; j++) {
        // Insert a[j] to sorted array a[0...j-1]
        int key = a[j];
        int i = j-1;
        while (i >= 0 && a[i] > key) {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}


int main() {
    const int SIZE = 9;
    int a[9] = {10, 2, 8, 3, 7, 27, 5, 6, 9};
    printf("BEFORE SORTING:\n");
    displayArray(a, SIZE);
    insertionSort(a, SIZE);
    printf("AFTER SORTING:\n");
    displayArray(a, SIZE);
    if (isSorted(a, SIZE)) {
        printf("SORTING OK\n");
    } else {
        printf("SORTING FAILED\n");
    }

    return 0;
}
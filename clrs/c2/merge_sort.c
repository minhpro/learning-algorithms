#include <stdio.h>
#include "array_utils.h"

/*
* Merge 2 sorted array a[l..m] and a[m+1..r]
* Result: a sorted array a[l..r]
*/
void merge(int a[], int l, int m, int r) {
	int lsize = m - l + 1;
	int rsize = r - m; 
	// Temp arrays to store left and right subarray
	int L[lsize], R[rsize];
	arrayCopy(a, l, L, 0, lsize);
	arrayCopy(a, m+1, R, 0, rsize);

	int i = 0, j = 0, k = l;
	while (i < lsize && j < rsize) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	if (i < lsize) {
		arrayCopy(L, i, a, k, lsize - i);
	} else if (j < rsize) {
		arrayCopy(R, j, a, k, rsize - j);
	}
}

void mergeSort(int a[], int start, int end) {
	if (start == end) {
		return;
	}

	int middle = (start + end) / 2;
	mergeSort(a, start, middle);
	mergeSort(a, middle + 1, end);
	merge(a, start, middle, end);
}

int main() {
    const int SIZE = 9;
    int a[9] = {10, 2, 8, 3, 7, 27, 5, 6, 9};
    printf("BEFORE SORTING:\n");
    displayArray(a, SIZE);
    mergeSort(a, 0, SIZE-1);
    printf("AFTER SORTING:\n");
    displayArray(a, SIZE);
    if (isSorted(a, SIZE)) {
        printf("SORTING OK\n");
    } else {
        printf("SORTING FAILED\n");
    }

    return 0;
}


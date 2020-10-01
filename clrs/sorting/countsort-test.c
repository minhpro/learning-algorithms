#include <stdio.h>
#include "countsort.h"
#include "../array/array_utils.h"

int main() {
	const int SIZE = 10;
    int a[SIZE] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int b[SIZE];
    displayArray(a, SIZE);

    countsort(a, b, SIZE, 20);
    displayArray(b, SIZE);
    if (isSorted(b, SIZE)) {
    	printf("COUNT SORT is OK\n");
    } else {
    	printf("COUNT SORT is FAILED\n");
    }
    int c[SIZE] = {4, 1, 3, 2, -16, 9, 10, 14, -8, 7};
    displayArray(c, SIZE);
    rangeCountSort(c, b, SIZE, -20, 20);
    displayArray(b, SIZE);
    if (isSorted(b, SIZE)) {
    	printf("RANGE COUNT SORT is OK\n");
    } else {
    	printf("RANGE COUNT SORT is FAILED\n");
    }

	return 0;
}

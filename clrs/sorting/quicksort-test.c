#include <stdio.h>
#include "quicksort.h"
#include "../array/array_utils.h"

int main() {
	const int SIZE = 10;
    int a[SIZE] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    displayArray(a, SIZE);

    quicksort(a, 0, SIZE - 1);
    displayArray(a, SIZE);
    if (isSorted(a, SIZE)) {
    	printf("QUICK SORT is OK\n");
    } else {
    	printf("QUICK SORT is FAILED\n");
    }

	return 0;
}

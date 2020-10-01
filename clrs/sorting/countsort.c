#include "countsort.h"
#include "../array/array_utils.h"

void countsort(int a[], int b[], int len, int max) {
    int count[max];
    fillArray(count, max, 0);

    for (int i = 0; i < len; i++) {
        count[a[i]]++; // count number of appearence of a[i]
    }

    for (int i = 1; i < max; i++) {
        count[i] += count[i-1]; // count number of elements of the array smaller or equal i
    }

    for (int i = len - 1; i >= 0; i--) {
        b[count[a[i]] - 1] = a[i]; // store a[i] to correct position in the result array
        count[a[i]]--;
    }
}

void rangeCountSort(int a[], int b[], int len, int min, int max) {
    int range = max - min;
    int c[len];
    for (int i = 0; i < len; i++) {
        c[i] = a[i] - min;
    }
    countsort(c, b, len, range);
    for (int i = 0; i < len; i++) {
        b[i] = b[i] + min;
    }
}

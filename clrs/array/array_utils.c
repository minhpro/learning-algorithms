#include <stdio.h>
#include "array_utils.h"

void displayArray(int a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

bool isSorted(int a[], int len) {
    for (int i = 1; i < len; i++) {
        if (a[i-1] > a[i]) {
            return false;
        }
    }

    return true;
}

void arrayCopy(int a[], int sa, int b[], int sb, int len) {
    for (int i = 0; i < len; i++) {
        b[sb+i] = a[sa+i];
    }
}

bool isEqual(int a[], int b[], int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i])
            return false;
    }

    return true;
}

#include <stdio.h>
#include <stdbool.h>
#include "../array/array_utils.h"
#include <memory.h>

int parent(int i);

int left(int i);

int right(int i);

bool heapVerify(int a[], int size);

/**
 * Build a heap with root at i with assume that left and right of i are heaps
 */ 
void maxHeapify(int a[], int i, int size);

void buildMaxHeap(int a[], int len);

void exchange(int a[], int i, int j);

void heapSort(int a[], int len);

int heapMaximum(int a[]);

int heapExtractMax(int a[], int size);

void maxHeapInsert(int key, int a[], int size);

void heapIncreaseKey(int i, int increase, int a[], int size);

void heapDelete(int i, int a[], int size);

int main() {
    const int SIZE = 10;
    static const int test[SIZE] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int a[SIZE];
    memcpy(a, test, sizeof(test));
    buildMaxHeap(a, SIZE);
    if (heapVerify(a, SIZE)) {
        printf("HEAP is valid\n");
    } else {
        printf("HEAP is invalid\n");
    }

    int b[SIZE];
    memcpy(b, test, sizeof(test));
    heapSort(b, SIZE);
    displayArray(b, SIZE);
    if (isSorted(b, SIZE)) {
        printf("HEAP SORT OK!\n");
    } else {
        printf("HEAP SORT FAILED!\n");
    }

    int c[SIZE];
    for (int i = 0; i < SIZE; i++) {
        maxHeapInsert(test[i], c, i);
    }

    displayArray(c, SIZE);  
    if (heapVerify(a, SIZE)) {
        printf("HEAP is valid\n");
    } else {
        printf("HEAP is invalid\n");
    }

}

void heapSort(int a[], int len) {
    buildMaxHeap(a, len);
    int heapSize = len;
    for (int i = len - 1; i >= 1; i--) {
        exchange(a, 0, i);
        heapSize--;
        maxHeapify(a, 0, heapSize);
    }
}

void buildMaxHeap(int a[], int len) {
    for (int i = (len - 1) / 2; i >= 0; i--) {
        maxHeapify(a, i, len);
    }
}

void maxHeapify(int a[], int i, int size) {
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l < size && a[largest] < a[l])
        largest = l;
    if (r < size && a[largest] < a[r])
        largest = r;

    if (largest != i) {
        exchange(a, i, largest);
        maxHeapify(a, largest, size);
    }
}

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

bool heapVerify(int a[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[parent(i)] < a[i]) 
            return false;
    }

    return true;
}

void exchange(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int heapMaximum(int a[]) {
    return a[0];
}

int heapExtractMax(int a[], int size) {
    int last = size - 1;
    exchange(a, 0, last);
    maxHeapify(a, 0, size - 1);
    return a[last];
}

void heapIncreaseKey(int i, int increase, int a[], int size) {
    a[i] += increase;
    while (i > 0 && a[i] > a[parent(i)]) {
        exchange(a, i, parent(i));
        i = parent(i);
    }
}

void maxHeapInsert(int key, int a[], int size) {
    size++;
    int last = size - 1;
    a[last] = key - 1;
    heapIncreaseKey(last, 1, a, size);
}

void heapDelete(int i, )

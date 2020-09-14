#include <stdio.h>
#include <stdbool.h>

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

int main() {
    const int SIZE = 10;
    int a[SIZE] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    // buildMaxHeap(a, SIZE);
    // if (heapVerify(a, SIZE)) {
    //     printf("HEAP is valid\n");
    // } else {
    //     printf("HEAP is invalid\n");
    // }

    heapSort(a, SIZE);
    
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

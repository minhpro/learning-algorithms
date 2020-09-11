#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int left, rigt, sum;
} MaxSubArray;

bool isMaxSubArrayEqual(MaxSubArray x, MaxSubArray y);

/**
 * Find a subarray has maximum sum
 */
MaxSubArray findMaxSubArray(int a[], int start, int end);

/**
 * Find a subarray cross the mid and has maximum sum
 */
MaxSubArray findMaxCrossSubArray(int a[], int left, int mid, int right);

/**
 * Find a subarray from start is maximum sum
 * direction: 1 find from start to end as right direction, -1 is left
 */
MaxSubArray findMaxSubArrayFrom(int a[], int start, int end, int direction);

MaxSubArray max(MaxSubArray a, MaxSubArray b, MaxSubArray c);

int main() {
    int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    MaxSubArray maxSub = {7, 10, 43};

    if (isMaxSubArrayEqual(maxSub, findMaxSubArray(a, 0, 16))) {
        printf("Find max subarray OK");
    } else {
        printf("Find max subarray Failed");
    }
    return 0;
}

bool isMaxSubArrayEqual(MaxSubArray x, MaxSubArray y) {
    if (x.left != y.left || x.rigt != y.rigt)
        return false;
    
    return true;
}

MaxSubArray findMaxSubArray(int a[], int start, int end) {
    MaxSubArray maxSub = {0, 0, 0};
    if (start >= end)
        return maxSub;

    int mid = start + (end - start) / 2;

    MaxSubArray leftSubMax = findMaxSubArray(a, start, mid);
    MaxSubArray rightSubMax = findMaxSubArray(a, mid+1, end);
    MaxSubArray crossSubMax = findMaxCrossSubArray(a, start, mid, end);
    
    return max(leftSubMax, rightSubMax, crossSubMax);
}

MaxSubArray findMaxCrossSubArray(int a[], int left, int mid, int right) {
    MaxSubArray leftMax = findMaxSubArrayFrom(a, mid, left, -1);
    MaxSubArray rightMax = findMaxSubArrayFrom(a, mid + 1, right, 1);
    int maxSum = leftMax.sum + rightMax.sum;
    MaxSubArray crossMax = {leftMax.left, rightMax.rigt, maxSum};
    return crossMax;
}

MaxSubArray findMaxSubArrayFrom(int a[], int start, int end, int direction) {
    int maxIndex = start;
    int maxSum = start;
    int sum = 0;

    for (int i = start; i != end; i = i + direction) {
        sum += a[i];
        if (sum > maxSum) {
            maxSum = sum;
            maxIndex = i;
        }
    }

    MaxSubArray answer = {start, maxIndex, maxSum};
    return answer;
}

MaxSubArray max(MaxSubArray a, MaxSubArray b, MaxSubArray c) {
    MaxSubArray maxValue = a;
    if (b.sum > maxValue.sum) maxValue = b;
    if (c.sum > maxValue.sum) maxValue = c;
    return maxValue;
}

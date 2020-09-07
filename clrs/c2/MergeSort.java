
public class MergeSort {

    /*
    * Merge 2 sorted array a[l..m] and a[m+1..r]
    * Result: a sorted array a[l..r]
    */
    public static void merge(int a[], int l, int m, int r) {
        int lsize = m - l + 1;
        int rsize = r - m; 
        // Temp arrays to store left and right subarray
        int[] L = new int[lsize], R = new int[rsize];
        ArrayUtils.arrayCopy(a, l, L, 0, lsize);
        ArrayUtils.arrayCopy(a, m+1, R, 0, rsize);

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
            ArrayUtils.arrayCopy(L, i, a, k, lsize - i);
        } else if (j < rsize) {
            ArrayUtils.arrayCopy(R, j, a, k, rsize - j);
        }
    }

    public static void mergeSort(int a[], int start, int end) {
        if (start == end) {
            return;
        }

        int middle = (start + end) / 2;
        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end);
        merge(a, start, middle, end);
    }

    public static void main(String[] args) {
        int a[] = {10, 2, 8, 3, 7, 27, 5, 6, 9};
        System.out.printf("BEFORE SORTING:\n");
        ArrayUtils.displayArray(a, a.length);
        mergeSort(a, 0, a.length - 1);
        System.out.printf("AFTER SORTING:\n");
        ArrayUtils.displayArray(a, a.length);
        if (ArrayUtils.isSorted(a, a.length)) {
            System.out.printf("SORTING OK\n");
        } else {
            System.out.printf("SORTING FAILED\n");
        }
    }
}
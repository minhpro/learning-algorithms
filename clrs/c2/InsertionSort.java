
public class InsertionSort {

    public static void insertionSort(int[] a, int len) {
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


    public static void main(String[] args) {
        int a[] = {10, 2, 8, 3, 7, 27, 5, 6, 9};
        System.out.printf("BEFORE SORTING:\n");
        ArrayUtils.displayArray(a, a.length);
        insertionSort(a, a.length);
        System.out.printf("AFTER SORTING:\n");
        ArrayUtils.displayArray(a, a.length);
        if (ArrayUtils.isSorted(a, a.length)) {
            System.out.printf("SORTING OK\n");
        } else {
            System.out.printf("SORTING FAILED\n");
        }
    }
}
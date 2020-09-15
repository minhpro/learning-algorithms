public class ArrayUtils {
	public static void displayArray(int a[], int len) {
        for (int i = 0; i < len; i++) {
            System.out.printf("%d\t", a[i]);
        }
        System.out.printf("\n");
    }
    
    public static boolean isSorted(int a[], int len) {
        for (int i = 1; i < len; i++) {
            if (a[i-1] > a[i]) {
                return false;
            }
        }
    
        return true;
    }


    public static void arrayCopy(int a[], int sa, int b[], int sb, int len) {
        for (int i = 0; i < len; i++) {
            b[sb+i] = a[sa+i];
        }
    }
}
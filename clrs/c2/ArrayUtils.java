public class ArrayUtils {
	public static void displayArray(int a[]) {
        int len = a.length;
        for (int i = 0; i < len; i++) {
            System.out.printf("%d\t", a[i]);
        }
        System.out.printf("\n");
    }
    
    public static boolean isSorted(int a[]) {
        int len = a.length;
        for (int i = 1; i < len; i++) {
            if (a[i-1] > a[i]) {
                return false;
            }
        }
    
        return true;
    }
}
#include <stdio.h>
#include <stdbool.h>

void matrixDisplay(int m, int n, int a[m][n]);

/**
 * Test matrix equality, m and n are matrix dimensions
 */ 
bool matrixEqual(int m, int n, int a[m][n], int b[m][n]);

/**
 * Perform matrix mutilplication: c = a x b
 */
void multiple(int m, int n , int p, int a[m][n], int b[n][p], int c[m][p]);

int main() {
    int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int b[2][3] = {{1, 0, 1}, {0, 1, 2}};
    int c[3][3] = {{1, 2, 5}, {3, 4, 11}, {5, 6, 17}};

    printf("Matrix a: \n");
    matrixDisplay(3, 2, a);
    printf("Matrix b: \n");
    matrixDisplay(2, 3, b);
    printf("Matrix c: \n");
    matrixDisplay(3, 3, c);

    int d[3][3];
    multiple(3, 2, 3, a, b, d);
    printf("Matrix d: \n");
    matrixDisplay(3, 3, d);

    if (matrixEqual(3, 3, c, d)) {
        printf("Matrix multiplication OK!\n");
    } else {
        printf("Matrix multilplication FAILED!\n ");
    }

    return 0;
}

void matrixDisplay(int m, int n, int a[m][n]) {
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            printf("%d\t", a[r][c]);
        }
        printf("\n");
    }
}

bool matrixEqual(int m, int n, int a[m][n], int b[m][n]) {
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (a[r][c] != b[r][c])
                return false;
        }
    }
    return true;
}

void multiple(int m, int n , int p, int a[m][n], int b[n][p], int c[m][p]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) 
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

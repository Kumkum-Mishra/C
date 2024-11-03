#include <stdio.h>

int main() {
    int m, n, i, j, zeroCount = 0, nonZeroCount = 0;

    // Input the dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    int matrix[m][n]; // Declare the matrix

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == 0) {
                zeroCount++;
            } else {
                nonZeroCount++;
            }
        }
    }

    // Check if the matrix is sparse
    if(zeroCount > nonZeroCount) {
        printf("The matrix is sparse.\n");
    } else {
        printf("The matrix is not sparse.\n");
    }

    return 0;
}

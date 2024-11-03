/*Write “C” program for performing following operations on matrices.
a. Accept two matrices from user and display their product if 
they are compatible else a suitable message.
b. Finding min and max element in the resultant matrix.
c. Finding sum of all the boundary elements of the resultant 
matrix.
*/
#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int mat2[MAX_SIZE][MAX_SIZE], int rows2, int cols2, int result[MAX_SIZE][MAX_SIZE]);
void findMinMax(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, int *min, int *max);
int sumBoundaryElements(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    // Input for the first matrix
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter elements for the first matrix:\n");
    inputMatrix(mat1, rows1, cols1);

    // Input for the second matrix
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    printf("Enter elements for the second matrix:\n");
    inputMatrix(mat2, rows2, cols2);

    // Multiplication
    if (cols1 == rows2) {
        multiplyMatrices(mat1, rows1, cols1, mat2, rows2, cols2, result);
        printf("Product of the matrices:\n");
        displayMatrix(result, rows1, cols2);

        // Finding min and max element in the resultant matrix
        int min, max;
        findMinMax(result, rows1, cols2, &min, &max);
        printf("Minimum element in the resultant matrix: %d\n", min);
        printf("Maximum element in the resultant matrix: %d\n", max);

        // Finding sum of boundary elements in the resultant matrix
        int boundarySum = sumBoundaryElements(result, rows1, cols2);
        printf("Sum of boundary elements in the resultant matrix: %d\n", boundarySum);
    } else {
        printf("Matrices are not compatible for multiplication.\n");
    }

    return 0;
}

// Function to input elements into a matrix
void inputMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display elements of a matrix
void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int mat2[MAX_SIZE][MAX_SIZE], int rows2, int cols2, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to find min and max elements in a matrix
void findMinMax(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, int *min, int *max) {
    *min = mat[0][0];
    *max = mat[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] < *min) {
                *min = mat[i][j];
            }
            if (mat[i][j] > *max) {
                *max = mat[i][j];
            }
        }
    }
}

// Function to find the sum of boundary elements in a matrix
int sumBoundaryElements(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                sum += mat[i][j];
            }
        }
    }
    return sum;
}
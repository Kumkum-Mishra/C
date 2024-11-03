#include <stdio.h>

int main() {
    int A[2][2] = {{1, 2}, {3, 4}}; // Example matrix A
    int B[2][2] = {{2, 3}, {4, 5}}; // Example matrix B
    int C[2][2]; // Matrix for storing results
    int i, j, k;

    // Addition
    printf("Addition of A and B: \n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Subtraction
    printf("Subtraction of B from A: \n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Multiplication
    // Resetting C to 0
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            C[i][j] = 0;
        }
    }

    printf("Multiplication of A and B: \n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            for(k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Transpose of A
    printf("Transpose of A: \n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }

    return 0;
}

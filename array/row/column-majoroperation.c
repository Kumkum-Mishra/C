#include <stdio.h>

int main() {
    int m, n;
    int i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);

    int arr[m][n]; 
    printf("\nEnter the elements in the array: \n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nThe array you entered is:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", arr[i][j]); // Added a space for readability
        }
        printf("\n");
    }

   int baseAddress = (int)&arr[0][0];

    printf("Row-major order addresses:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            //  Calculate address in row-major order
            int address = baseAddress + ((i * n) + j) *sizeof(int);
            printf("arr[%d][%d]: %d\n", i, j, address);
        }
    }

    printf("\nColumn-major order addresses (theoretical):\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            // Calculate address in column-major order
            int address = baseAddress + ((j * m) + i) * sizeof(int);
            printf("arr[%d][%d]: %d\n", i, j, address);
        }
    }

    return 0;
} 

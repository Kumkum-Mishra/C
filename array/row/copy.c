#include <stdio.h>

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int i, j;
    int rows = 3;
    int cols = 4;
    int sizeOfElement = sizeof(arr[0][0]);
    int baseAddress = (int)&arr[0][0];

    printf("Row-major order addresses:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            // Correct calculation for row-major order
            int address = baseAddress + ((i * cols) + j) * sizeOfElement;
            printf("arr[%d][%d]: %p\n", i, j, (void *)address);
        }
    }

    printf("\nColumn-major order addresses (theoretical):\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            // Calculate address in column-major order
            int address = baseAddress + ((j * rows) + i) * sizeOfElement;
            printf("arr[%d][%d]: %p\n", i, j, (void *)address);
        }
    }

    return 0;
}

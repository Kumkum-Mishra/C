#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random integers and store them in a file
void generateRandomIntegers(const char *filename, int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", rand() % 100); // Assuming a range of 0 to 99 for simplicity
    }

    fclose(file);
}

// Function to read numbers from a file and create an N x N matrix
void readNumbersAndCreateMatrix(const char *filename, int matrix[][10], int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error reading from file");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}

// Function to multiply two matrices and store the result in a file
void multiplyMatricesAndStoreResult(const char *filename, int matrix1[][10], int matrix2[][10], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int resultMatrix[10][10] = {0};

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Write the result to the file
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%d ", resultMatrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    const char *file1 = "f1.txt";
    const char *file2 = "f2.txt";
    const char *file3 = "f3.txt";
    const int size = 3; // Adjust the size of the matrices as needed

    // Generate random integers and store them in files
    generateRandomIntegers(file1, size * size);
    generateRandomIntegers(file2, size * size);

    // Read numbers from files and create matrices
    int matrix1[10][10], matrix2[10][10];
    readNumbersAndCreateMatrix(file1, matrix1, size);
    readNumbersAndCreateMatrix(file2, matrix2, size);

    // Multiply matrices and store the result in a file
    multiplyMatricesAndStoreResult(file3, matrix1, matrix2, size);

    printf("Matrices multiplied and result stored in f3.txt.\n");

    return 0;
}

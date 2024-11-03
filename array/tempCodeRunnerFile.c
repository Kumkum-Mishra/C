#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1;
    int *arr2;
    int n = 5;
    int i;

    // Allocate memory for arr1 using malloc()
    arr1 = (int*)malloc(n * sizeof(int));
    if(arr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Memory allocated using malloc:\n");
    for(i = 0; i < n; i++) {
        arr1[i] = i + 1;  // Assign values
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Allocate memory for arr2 using calloc()
    arr2 = (int*)calloc(n, sizeof(int));
    if(arr2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Memory allocated using calloc:\n");
    for(i = 0; i < n; i++) {
        arr2[i] = (i + 1) * 10;  // Assign values
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Resize arr1 using realloc()
    int new_size = n + 5; // Increase size
    arr1 = (int*)realloc(arr1, new_size * sizeof(int));
    if(arr1 == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }
    printf("Memory reallocated using realloc:\n");
    for(i = n; i < new_size; i++) {
        arr1[i] = (i + 1);  // Assign new values
    }
    for(i = 0; i < new_size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr1);
    free(arr2);

    printf("Memory freed.\n");

    return 0;
}

#include <stdio.h>

void printSubset(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void findSubsets(int arr[], int n, int index, int subset[], int subsetSize) {
    if (index == n) {
        printSubset(subset, subsetSize);
        return;
    }

    findSubsets(arr, n, index + 1, subset, subsetSize);

    subset[subsetSize] = arr[index];
    findSubsets(arr, n, index + 1, subset, subsetSize + 1);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[n];  

    findSubsets(arr, n, 0, subset, 0);

    return 0;
}
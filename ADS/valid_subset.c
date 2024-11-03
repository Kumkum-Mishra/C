#include <stdio.h>

int isSubset(int arr[], int arrSize, int subset[], int subsetSize) {
    for (int i = 0; i < subsetSize; i++) {
        int found = 0;
        for (int j = 0; j < arrSize; j++) {
            if (subset[i] == arr[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int subset[] = {5, 7, 9, 10};

    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int subsetSize = sizeof(subset) / sizeof(subset[0]);

    if (isSubset(arr, arrSize, subset, subsetSize)) {
        printf("yes it is a subset\n");
    } else {
        printf("No it is not a subset\n");
    }

    return 0;
}

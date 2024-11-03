#include <stdio.h>

void removeDuplicates(int arr[], int n) {

    int temp[n];
    int j = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i];
        }
    }
    temp[j++] = arr[n - 1];
    
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }
    
    printf("Array after removing duplicates: ");
    for (int i = 0; i < j; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 5, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    removeDuplicates(arr, n);
    
    return 0;
}
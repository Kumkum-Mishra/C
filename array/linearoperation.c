#include <stdio.h>

#define MAX_SIZE 100

void insertElement(int arr[], int *size, int k, int element) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }

    if (k < 0 || k > *size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    // Shift elements to make space for the new element
    for (int i = *size; i > k; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element at the specified position
    arr[k] = element;
    (*size)++;

    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *size, int k) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }

    if (k < 0 || k >= *size) {
        printf("Invalid position for deletion.\n");
        return;
    }

    // Shift elements to fill the gap left by the deleted element
    for (int i = k; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element deleted successfully.\n");
}

void traverseArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, position, element;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an element at Kth position\n");
        printf("2. Delete an element from Kth position\n");
        printf("3. Traverse the array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertElement(arr, &size, position, element);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;

            case 3:
                traverseArray(arr, size);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
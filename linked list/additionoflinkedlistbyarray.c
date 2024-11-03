// modify it for user defined nodes and elemnets of both the list later


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to store elements of a linked list into an array
int listToArray(struct Node* head, int arr[]) {
    int i = 0;
    while (head != NULL) {
        arr[i++] = head->data;
        head = head->next;
    }
    return i; // Return the number of elements stored
}

// Function to add elements of two arrays and store the result in a third array
int addArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i, sumSize = (size1 > size2) ? size1 : size2;
    for (i = 0; i < sumSize; i++) {
        int val1 = (i < size1) ? arr1[i] : 0;
        int val2 = (i < size2) ? arr2[i] : 0;
        result[i] = val1 + val2;
    }
    return sumSize; // Return the size of the resultant array
}

// Function to convert an array into a linked list
void arrayToList(struct Node** head_ref, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        insert(head_ref, arr[i]);
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* resultList = NULL;

    // Example lists
    insert(&list1, 1);
    insert(&list1, 2);
    insert(&list1, 3);
    insert(&list2, 4);
    insert(&list2, 5);
    insert(&list2, 6);

    // Arrays to store list elements and their sums
    int arr1[100], arr2[100], sumArray[100];
    int size1, size2, sumSize;

    // Convert lists to arrays
    size1 = listToArray(list1, arr1);
    size2 = listToArray(list2, arr2);

    // Add arrays
    sumSize = addArrays(arr1, size1, arr2, size2, sumArray[100]);

    // Convert the sum array back to a list
    arrayToList(&resultList, sumArray[100], sumSize);

    printf("List 1: ");
    printList(list1);
    printf("\nList 2: ");
    printList(list2);
    printf("\nResult List: ");
    printList(resultList);

    return 0;
}
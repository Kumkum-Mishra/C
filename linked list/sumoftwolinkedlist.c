#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to print a linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to add two linked lists
struct Node* addTwoLists(struct Node* l1, struct Node* l2) {
    // Reverse both linked lists
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    struct Node* result = NULL;
    struct Node* temp = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = sum % 10;
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    if (carry > 0) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = carry;
        newNode->next = NULL;

        temp->next = newNode;
    }

    // Reverse the resulting linked list
    result = reverseList(result);

    return result;
}

int main() {
    // Create the first linked list: 7 -> 5 -> 9 -> 4 -> 6
    struct Node* l1 = (struct Node*)malloc(sizeof(struct Node));
    l1->data = 6;
    l1->next = (struct Node*)malloc(sizeof(struct Node));
    l1->next->data = 5;
    l1->next->next = (struct Node*)malloc(sizeof(struct Node));
    l1->next->next->data = 9;
    l1->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    l1->next->next->next->data = 4;
    l1->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    l1->next->next->next->next->data = 7;
    l1->next->next->next->next->next = NULL;

    // Create the second linked list: 8 -> 4
    struct Node* l2 = (struct Node*)malloc(sizeof(struct Node));
    l2->data = 4;
    l2->next = (struct Node*)malloc(sizeof(struct Node));
    l2->next->data = 8;
    l2->next->next = NULL;

    printf("First List: ");
    printList(l1);
    printf("Second List: ");
    printList(l2);

    struct Node* result = addTwoLists(l1, l2);
    printf("Sum List: ");
    printList(result);
    return 0; 
    }
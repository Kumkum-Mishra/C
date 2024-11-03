#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a new element onto the stack
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop the top element from the stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }

    Node* temp = *top;
    int poppedData = temp->data;
    *top = temp->next;
    free(temp);
    return poppedData;
}

// Function to display the top element of the stack
void showTop(Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

// Function to check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

int main() {
    int userDefinedSize, i;
    printf("Enter the size of the stack: ");
    if (scanf("%d", &userDefinedSize) == 0 || userDefinedSize <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    Node* top = NULL;

    for (i = 0; i < userDefinedSize; i++) {
        int userDefinedValue;
        printf("Enter the value to push onto the stack: ");
        if (scanf("%d", &userDefinedValue) == 0) {
            printf("Invalid input. Please enter an integer.\n");
            return 1;
        }
        push(&top, userDefinedValue);
    }

    for (i = 0; i < userDefinedSize; i++) {
        showTop(top);
        pop(&top);
    }

    return 0;
}
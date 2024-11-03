#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int data;
    struct Stack* next;
};

struct Stack* top = NULL; // Define top pointer globally

void push();
int pop();
void display();
int peek();
int size();
int isEmpty();
int isFull(); // Always returns false for linked list implementation
void clear();

int main() {
    int choice, value;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Size\n6. Is Empty\n7. Is Full\n8. Clear\n9. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                value = pop();
                if(value != -1) {      
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if(value != -1) {      
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Size of stack: %d\n", size());
                break;
            case 6:
                if (isEmpty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 7:
                if (isFull())
                    printf("Stack is full\n");
                else
                    printf("Stack is not full\n");
                break;
            case 8:
                clear();
                printf("Stack is cleared\n");
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 9);

    // Free memory for dynamically allocated nodes
    struct Stack* current = top;
    while(current != NULL) {
        struct Stack* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

void push() {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    int value = -1;
    if(top == NULL) {
        printf("Stack underflow\n");
    } else {
        struct Stack* temp = top;
        top = top->next;
        value = temp->data;
        free(temp);
    }
    return value;
}

int peek() {
    if(top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display() {
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    struct Stack* current = top;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int size() {
    int count = 0;
    struct Stack* current = top;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int isEmpty() {
    return top == NULL;
}

int isFull() {
    return false; // Always false for linked list implementation
}

void clear() {
    while (top != NULL) {
        struct Stack* temp = top;
        top = top->next;
        free(temp);
    }
}

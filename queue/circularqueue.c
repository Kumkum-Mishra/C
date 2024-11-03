#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Change the maximum size of the circular queue as needed

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    do {
        printf("\n---Circular Queue Operations---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void enqueue() {
    int data;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the value to enqueue: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    
    // Check if the circular queue is full
    if ((front == rear && front != NULL && rear != NULL && rear->next == front) ||
        (front == NULL && rear != NULL && rear->next == front)) {
        printf("Queue is full. Enqueue operation failed.\n");
        free(newnode);
        return;
    }
    
    // If the queue is empty
    if (front == NULL && rear == NULL) {
        front = rear = newnode;
        rear->next = front; // Make the circular link
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front; // Make the circular link
    }
    printf("Enqueued successfully.\n");
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }
    
    struct node* temp = front;
    printf("Dequeued element: %d\n", front->data);
    
    // If there is only one element in the queue
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // Update the circular link
    }
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue elements: ");
    struct node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

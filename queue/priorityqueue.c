#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int priority;
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
        printf("\n---Priority Queue Operations---\n");
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
    int data, priority;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the value to enqueue: ");
    scanf("%d", &data);
    printf("Enter the priority of the value: ");
    scanf("%d", &priority);
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;
    
    // If the queue is empty or the new element has higher priority than the front element
    if (front == NULL || priority > front->priority) {
        newnode->next = front;
        front = newnode;
    } else {
        struct node* temp = front;
        // Traverse the queue to find the correct position to insert the new element
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("Enqueued successfully.\n");
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }
    struct node* temp = front;
    front = front->next;
    free(temp);
    printf("Dequeued successfully.\n");
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    struct node* temp = front;
    while (temp != NULL) {
        printf("(%d, priority: %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

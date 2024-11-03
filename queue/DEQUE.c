#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueueFront();
void enqueueRear();
void dequeueFront();
void dequeueRear();
void display();

int main() {
    int choice;
    do {
        printf("\n---Deque Operations---\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display deque\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueueFront();
                break;
            case 2:
                enqueueRear();
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}


void enqueueFront() {
    int data;
    printf("Enter the value to enqueue at front: ");
    scanf("%d", &data);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->data = data;
    newnode->next = front;
    front = newnode;

    if (rear == NULL) {
        rear = newnode;
    }

    printf("Enqueued at front successfully.\n");
}

void enqueueRear() {
    int data;
    printf("Enter the value to enqueue at rear: ");
    scanf("%d", &data);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->data = data;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Enqueued at rear successfully.\n");
}

void dequeueFront() {
    if (front == NULL) {
        printf("Deque is empty. Nothing to dequeue from front.\n");
        return;
    }

    struct node* temp = front;
    front = front->next;
    free(temp);

    if (front == NULL) {
        rear = NULL;
    }

    printf("Dequeued value from front.\n");
}

void dequeueRear() {
    if (rear == NULL) {
        printf("Deque is empty. Nothing to dequeue from rear.\n");
        return;
    }

    if (front == rear) {
        free(rear);
        front = rear = NULL;
        printf("Dequeued value from rear.\n");
        return;
    }

    struct node* temp = front;
    while (temp->next != rear) {
        temp = temp->next;
    }

    temp->next = NULL;
    free(rear);
    rear = temp;

    printf("Dequeued value from rear.\n");
}

void display() {
    if (front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    struct node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

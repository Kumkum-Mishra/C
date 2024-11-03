#include <stdio.h>
#include <stdlib.h>

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
        printf("\n---Queue Operations---\n");
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
    printf("Enter the value to enqueue: ");
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

    printf("Enqueued successfully.\n");
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }

    struct node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }

    printf("Dequeued value: %d\n", temp->data);
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

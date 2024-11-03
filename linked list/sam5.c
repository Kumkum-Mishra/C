#include <stdio.h>
#define MAX_SIZE 100 // Maximum size of the list

int list[MAX_SIZE]; // The list itself
int size = 0; // Current size of the list (number of elements)

void addElement(int element);
void display();
void insertAtPosition(int position, int element);
void deleteAtPosition(int position);

int main() {
    int choice, element, position;

    do {
        printf("\n---List Operations---\n");
        printf("1. Add element to the end\n");
        printf("2. Display list\n");
        printf("3. Insert element at a specific position\n");
        printf("4. Delete element from a specific position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &element);
                addElement(element);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the position to insert the element: ");
                scanf("%d", &position);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtPosition(position, element);
                break;
            case 4:
                printf("Enter the position to delete the element: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
    while(choice!=5);
    {
    return 0;
}
}

void addElement(int element) {
    if(size < MAX_SIZE) {
        list[size] = element; // Add the element to the end of the list
        size++; // Increase the size of the list
    } else {
        printf("List is full. Cannot add more elements.\n");
    }
}

void display() {
    if(size == 0) {
        printf("List is empty.\n");
    } else {
        printf("List elements: ");
        for(int i = 0; i < size; i++) {
            printf("%d ", list[i]);
        }
        printf("\n");
    }
}

void insertAtPosition(int position, int element) {
    if(size >= MAX_SIZE) {
        printf("List is full. Cannot insert new element.\n");
        return;
    }

    if(position < 0 || position > size) { // Check for valid position
        printf("Invalid position. Please enter a position between 0 and %d.\n", size);
        return;
    }

    for(int i = size; i > position; i--) { // Shift elements to the right
        list[i] = list[i-1];
    }

    list[position] = element; // Insert the new element
    size++;
}

void deleteAtPosition(int position) {
    if(position < 0 || position >= size) {
        printf("Invalid position.\n");
        return;
    }

    for(int i = position; i < size - 1; i++) { // Shift elements to the left
        list[i] = list[i+1];
    }

    size--; // Decrease the size of the list
}

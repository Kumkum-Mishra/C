#include <stdio.h>
#define MAX_SIZE 100 // Maximum size of the list

int list[MAX_SIZE]; // The list itself
int size = 0; // Current size of the list (number of elements)

// Function to add an element to the end of the list
void addElement(int element) {
    if(size < MAX_SIZE) {
        list[size] = element; // Add the element to the end of the list
        size++; // Increase the size of the list
    } else {
        printf("List is full. Cannot add more elements.\n");
    }
}

// Function to display all elements in the list
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

// Function to insert an element at a specific position
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

// Function to delete an element at a specific position
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

int main() {
    // Example usage
    addElement(10); // Add elements
    addElement(20);
    display(); // Should display: 10 20
    
    insertAtPosition(1, 15); // Insert element at position 1
    display(); // Should display: 10 15 20
    
    deleteAtPosition(1); // Delete element at position 1
    display(); // Should display: 10 20
    
    return 0;
}

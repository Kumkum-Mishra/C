#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *s; // Changed 's' to be a pointer to an integer
};

struct stack *st;

void push() {
    int data;
    if(st->top == st->size - 1) { // Use 'st->top' and 'st->size'
        printf("Stack overflows\n");
    } else {
        printf("Enter the data: ");
        scanf("%d", &data);
        st->top++;
        st->s[st->top] = data; // Assign 'data' to the correct position
    }
}

int main() {
    int size;
    printf("enter the size of stack:");
    scanf("%d",&size);
    st = (struct stack *)malloc(sizeof(struct stack)); // Allocate memory for the stack
    st->size = size; // Example size
    st->top = -1; // Initialize 'top' to -1 to indicate an empty stack
    st->s = (int *)malloc(st->size * sizeof(int)); // Allocate memory for the stack elements

    push(); // Now you can call push

    // Don't forget to free the allocated memory at the end of your program
    free(st->s);
    free(st);

    return 0;
}

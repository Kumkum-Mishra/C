#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;   // Size of the stack
    int top;    // Index of the top element in the stack
    int *s;     // Pointer to the array representing the stack elements
};

void push(struct stack *st);
int pop(struct stack *st);
void display(struct stack *st); 
int peek(struct stack *st);    // Returns the top element
int isEmpty(struct stack *st);
int isFull(struct stack *st);
int size(struct stack *st);
void clear(struct stack *st);

int main() {
    struct stack *st; // name of stack means pointer pointing to whole stack
    int size;
    printf("Enter the size of stack: ");
    scanf("%d", &size);

    st = (struct stack*)malloc(sizeof(struct stack)); // Allocate memory for the stack
    if (st == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    st->size = size;
    st->top = -1;
    st->s = (int *)malloc(size * sizeof(int));
    if(st->s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice, value;
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Size\n6. Is Empty\n7. Is Full\n8. Clear\n9. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                push(st); // Pass the pointer to the stack
                break;
            case 2:
                value = pop(st); // Pass the pointer to the stack
                if(value != -1) {      
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(st);
                if(value != -1) {      
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                display(st); // Pass the pointer to the stack
                break;
            case 5:
                printf("Size of stack: %d\n", sizeof(st));
                break;
            case 6:
                if(isEmpty(st)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 7:
                if(isFull(st)) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            case 8:
                clear(st);
                printf("Stack is cleared\n");
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 9);

    free(st->s); // Free memory for stack elements
    free(st); // Free memory for the stack itself
    return 0;
}

void push(struct stack *st) {
    int data;
    if(st->top == st->size - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter the data: ");
        if(scanf("%d", &data) != 1) {
            printf("Invalid input\n");
            return;     
        }
        st->top++;
        st->s[st->top] = data;
    }
}

int pop(struct stack *st) {
    int value = -1;      
    if(st->top == -1) {
        printf("Stack underflow\n");
    } else {
        value = st->s[st->top];
        st->top--;
    }
    return value;
}

int peek(struct stack *st) {
    if(st->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return st->s[st->top];
}

int isEmpty(struct stack *st) {
    return st->top == -1;
}

int isFull(struct stack *st) {
    return st->top == st->size - 1;
}

int size(struct stack *st) {
    return st->top + 1;
}

void display(struct stack *st) {
    if(st->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = st->top; i >= 0; i--) {
        printf("%d ", st->s[i]);
    }
    printf("\n");
}

void clear(struct stack *st) {
    st->top = -1;
}

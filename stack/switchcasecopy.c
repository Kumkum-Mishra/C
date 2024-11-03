#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top; // Name of pointer to uppermost element box
    int *s;  // Name of stack elements boxes, here worked as temp pointer
};

void push(struct stack *st);
int pop(struct stack *st);
void display(struct stack *st); 

int main() {
    struct stack st; // Use stack object directly instead of a pointer
    int choice, value;

    printf("Enter the size of stack: ");
    scanf("%d", &st.size);

    st.top = -1;
    st.s = (int *)malloc(st.size * sizeof(int));
    if(st.s == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                push(&st);
                break;
            case 2:
                value = pop(&st);
                if(value != -1) { // Assuming -1 as an error code for underflow
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display(&st);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);

    free(st.s);
    return 0;
}

void push(struct stack *st) {
    int data;
    if(st->top == st->size - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter the data: ");
        // Step 1: Attempt to read an integer from the user input
       int result = scanf("%d", &data);

       // Step 2: Check if the reading was successful
       if(result != 1) {
       printf("Invalid input\n");
       return; // Early return if input is not valid
}
        st->top++;
        st->s[st->top] = data;
    }
}

int pop(struct stack *st) {
    int value = -1; // Assume -1 is error code for underflow
    if(st->top == -1) {
        printf("Stack underflow\n");
    } else {
        value = st->s[st->top];
        st->top--;
    }
    return value;
}

void display(struct stack *st) {
    if(st->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for(int i = st->top; i >= 0; i--) {
        printf("%d ", st->s[i]);
    }
    printf("\n");
}

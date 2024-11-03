#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;// name of pointer uppermost element box
    int *s;//name of stack elements boxes ,here worked as temp pointer
};
struct stack *st;//name of whole stack pointer
void push();
int pop();
void display(); 

int main() {
    int length, choice, value;

    printf("Enter the size of stack: ");
    scanf("%d", &length);
    if (length!=1)
    {
        printf("Invalid input\n");
        return 1; // Exit if the input is not valid
    }

    st.size = length;
    st.top = -1;
    st.s = (int *)malloc(st.size * sizeof(int));
    if(st.s == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    do {
        printf("\n1. Push\n2. Pop\n3. display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                value = pop();
                if(value != -1) { // Assuming -1 as an error code for underflow
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 4);

    free(st.s);
    return 0;
}
// main function ends here
void push(){
    int data;
    if(st->top == st->size - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter the data: ");
        if(scanf("%d", &data) != 1) {
            printf("Invalid input\n");
            return; // Early return if input is not valid
        }
        st->top++;
        st->s[st->top] = data;
    }
}
//push function ends here
int pop() {
    int value = -1; // Assume -1 is error code for underflow
    if(st->top == -1) {
        printf("Stack underflow\n");
    } else {
        value = st->s[st->top];
        st->top--;
    }
    return value;
}
//pop function ends here
void display() {
    for(int i = st.top; i >= 0; i--) {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}
//display function ends here

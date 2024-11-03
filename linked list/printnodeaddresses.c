#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node*next;
};

// Function to add a new node at the end of the list
void append(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    struct node *last = *head_ref;

    new_node->data  = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL) {
       *head_ref = new_node;
       return;
    } 

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return;    
}

void create(int arr[], int n, struct node** head) {
    for(int i = 0; i < n; i++) {
        append(head, arr[i]);
    }
}

void printaddresses(struct node* head) {
    struct node* current = head;
    while(current != NULL) {
        printf("%d %p\n", current->data, (void*)current);
        current = current->next;
    }
}

int main() {
    struct node* head = NULL;
    int A[] = {3, 7, 10};
    create(A, 3, &head);
    printaddresses(head);
    return 0;
}
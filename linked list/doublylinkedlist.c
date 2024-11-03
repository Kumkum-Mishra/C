#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node *head = NULL,*temp,*newnode;

void create();
void display();
void insertatposition();
void deleteatposition();

int main() {
    int choice;
    do {
        printf("\n---Doubly Linked List Operations---\n");
        printf("1. Create list\n");
        printf("2. Display list\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete from specific position\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insertatposition();
                break;
            case 4:
                deleteatposition();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);
}

void create() {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value of node %d: ", i + 1);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head == NULL) {
            head = newnode;
        } else {
            struct node* temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

void display() {
    temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertatposition() {
    int data, pos;
    printf("Enter the position at which you want to insert a new node: ");
    scanf("%d", &pos);
    printf("Enter the value of new node: ");
    scanf("%d", &data);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(pos == 1) {
        newnode->next = head;
        if(head != NULL) head->prev = newnode;
        head = newnode;
    } else {
        temp = head;
        for(int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if(temp == NULL) {
            printf("Position out of bounds\n");
            free(newnode);
            return;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if(temp->next != NULL) temp->next->prev = newnode;
        temp->next = newnode;
    }
    printf("Node inserted successfully\n");
}

void deleteatposition() {
    int pos;
    printf("Enter the position from which you want to delete the node: ");
    scanf("%d", &pos);

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    if(pos == 1) {
        head = temp->next;
        if(head != NULL) head->prev = NULL;
        free(temp);
    } else {
        for(int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }
        if(temp == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        struct node* prevnode=temp->prev;//pointing previous node to the previous position of temp.
        if(temp->next != NULL) temp->next->prev = temp->prev;
        if(temp->prev != NULL) prevnode->next= temp->next;
        free(temp);
    }
    printf("Node deleted successfully\n");
}

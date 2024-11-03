#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
struct node*head=NULL,*temp,*newnode;
void create();
void traverse();
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
                traverse();
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
    return 0;
}
// function of creation of node
void create() {
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return;
    }

    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory allocation fails.\n");
        return;
    }

    printf("Enter the value of node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation fails.\n");
            return;
        }
        printf("Enter the value of node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }

    temp->next = head; // Make the list circular
}

//funtion to print all the elements of the linked list
void traverse(){
    if (head==NULL)
    {
        printf("list is empty");
    }
    temp=head;
    do {
        printf("%d\t",temp->data);
        temp=temp->next;
        }
    while(temp!=head);
    printf("\n"); 
}
// function to insert at given position
void insertatposition() {
    int data,i,pos;
    printf("Enter the pos at which you want to enter the data:");
    scanf("%d",&pos);
    printf("Enter the data in the newnode node:");
    scanf("%d",&data);
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation fails");
        return;
    }
    newnode->data=data;
    if (pos==1){
       newnode->next=head;
       temp=head;
       if(head!=NULL){
       while(temp->next!=head){
        temp=temp->next;
       }
       temp->next=newnode;
       head=newnode;
       }
       else{
        newnode->next=newnode;
       }
     }
     else{
        temp=head;
        for(i=2;i>pos && temp->next!=head;i++)
        {temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
      } 
}
// function to delete the node at a particular position
void deleteatposition() {
    int pos, i;
    struct node *prev;
    printf("Enter the position from which you want to delete the node: ");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1) {
        temp = head;
        while (temp->next != head) {
            temp = temp->next; // Find the last node
        }
        if (head == head->next) { // Only one node in the list
            free(head);
            head = NULL;
        } else {
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
    } else {
        temp = head;
        for (i = 2; i < pos && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head) { // If position is out of range 
            printf("Position is out of range.\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
}


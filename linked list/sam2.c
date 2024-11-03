#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node* head = NULL, *temp, *newnode;

void create();
void display();
void insertatposition();
void deleteatposition();

int main() {
    int choice;
    do {
        printf("\n---Linked List Operations---\n");
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
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

// Define the create, display, insertatposition, and deleteatposition functions here
void create() {
    int n,data,i;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    if(n>0) {
    printf("enter the value of node 1:");
    scanf("%d->",&data);
    head=(struct node*)malloc(sizeof(struct node));
    head->data=data;
    head->next=NULL;
    temp=head;
    for(i=2;i<=n;i++)
    {
       newnode=(struct node*)malloc(sizeof(struct node));
       printf("enter the value of node %d:",i);
       scanf("%d->",&data);
       newnode->data=data;
       newnode->next=NULL;
       temp->next=newnode;
       temp=newnode;
    }
    }
}
void display() {
    if (head==NULL)
    {
      printf("list is empty");
    }
    else {
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
}
void insertatposition() {
   int data,pos,i;
   printf("Enter the position at which you want to insert new node:");
   scanf("%d",&pos);
   if(pos==1){
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("enter the value of new node to insert at beginning:");
   scanf("%d",&data);
   newnode->data=data;
   newnode->next=head;
   head=newnode;
}  else {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the value of new node:");
    scanf("%d",&data);
    newnode->data=data;
    temp=head;
    for(i=2;i<=pos;i++) {
        temp=temp->next;
      if (temp==NULL){
        printf("The position is not valid");
        free(newnode);
        return;
      }  
    }
    newnode->next=temp->next;
    temp->next=newnode;
    }
}

void deleteatposition() {
  struct node *todelete,*prevnode;
  int pos,i;
  printf("Enter the position at which you want to delete the node:");
  scanf("%d",&pos);
  if(head==NULL){
    printf("list is empty");
  }
  if(pos==1){
    todelete=head;
    head=head->next;
    free(todelete);
    return;
  }
  else {
  todelete=head;
  prevnode=head;
  for(i=1;i<pos && todelete!=NULL;i++)
{
  prevnode=todelete;
  todelete=todelete->next;
}  
  }
if (todelete==NULL){
  printf("The pos you have entered is beyond the bounds");
}
else {
  prevnode->next=todelete->next;
  free(todelete);
  return;
}
  }  


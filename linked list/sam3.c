#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head=NULL,*temp,*newnode;
void create();
void display ();
void insertatbegining();
void insertatposition();
void deleteatposition();
void reverselist();
int main() {
   create();
   printf("Original List:\n");
   display();
   insertatposition();
   printf("List after insertion:\n");
   display();
   deleteatposition();
   printf("List after deletion:\n");
   display();
   reverselist();
   printf("List after reversal:\n");
   display();
   return 0;
}

// Define the create, display, insertatposition, and deleteatposition functions here
void create() {
    int n,data,i;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    if(n>0) {
    head=(struct node*)malloc(sizeof(struct node));  
    printf("enter the value of node 1:");
    scanf("%d->",&data);
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
   printf("Enter the postion at which you want to insert new node:");
   scanf("%d",&pos);
   if(pos==1){
   printf("enter the value of new node to insert at beginning:");
   scanf("%d",&data);
   newnode=(struct node*)malloc(sizeof(struct node));
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
        printf("The position is not valid\n");
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
void reverselist() {
    struct node* prev = NULL;
    struct node* ahead = NULL;
    temp = head;
    while (temp != NULL) {
        ahead = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ahead;
    }
    head = prev; // Update the head pointer to the new first node.
}

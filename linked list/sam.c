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
int main() {
   create();
   display ();
   insertatbegining();
   display;
   insertatposition();
   display();
   deleteatposition();
   display();
   return 0;
}
void create() {
    int n,data,i;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    if(n>0) {
    printf("enter the value of node 1:");
    scanf("%d",&data);
    head=(struct node*)malloc(sizeof(struct node));
    head->data=data;
    head->next=NULL;
    temp=head;
    for(i=2;i<=n;i++)
    {
       newnode=(struct node*)malloc(sizeof(struct node));
       printf("enter the value of node %d:",i);
       scanf("%d",&data);
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
void insertatbegining() {
    int data;
   printf("enter the value of new node to insert at beginning:");
   scanf("%d",&data);
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data;
   newnode->next=head;
   head=newnode;
}
void insertatposition() {
    int pos,i,data;
    struct node* prevnode = NULL;
    printf("Enter the postion at which you want to insert new node:");
    scanf("%d",&pos);
    if (pos==1)
      {
        insertatbegining();
        return;
      }
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
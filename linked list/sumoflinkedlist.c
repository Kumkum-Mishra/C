#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head=NULL,*temp,*newnode;
void create();
void display ();
void add();

int main() {
   create();
   display();
   add();
   return 0;
}

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

void add(){
    temp=head;
    int sum=0;
    if( head==NULL){
        printf("List is empty");
    }
    else {
     while(temp!=NULL){
        sum=sum+temp->data;
        temp=temp->next;
     }
     printf("The sum of all the elements in the list is %d",sum);
    }
    return ;
}
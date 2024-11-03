#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};struct node*head=NULL,*temp,*newnode;
void create();
//void traverse();
void display();
int main(){
   create();
  // traverse();
    display();
   return 0;
}
void create(){
    int n,m,i;
    printf("enter the number of nodes:");
    scanf("%d",&m);
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter the value of node 1:");
    scanf("%d",&n);
    head->data=n;
    head->next=NULL;
    temp=head;
    for(i=2;i<=m;i++)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the value of node %d:",i);
    scanf("%d",&n);
    newnode->data=n;
    newnode->next=NULL;
    temp->next=newnode;
    temp=newnode;
    
}// for closes
} //create
void display()
{
    if(head==NULL){
        printf("list is empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
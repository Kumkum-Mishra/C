#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node *head=NULL,*temp,*newnode;
void create();
void display();
void insertatposition();
void deleteatposition();

int main(){
    int choice;
    do{
    printf("linked list operations:\n");
    printf("1.create a list\n");
    printf("2.display\n");
    printf("3.insert at position\n");
    printf("4.delete at position\n");
    printf("5.Exiting the program\n");

    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
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
        printf("Exit...");
        default :
        printf("Invalid choice,Please enter a valid choice");

    } 
    }
    while(choice!=5);
    return 0;
    }
    // Function to create a linked list
    void create(){
        int data,n,i;
        printf("Enter the number of nodes:");
        scanf("%d",&n);
        if (n>0){
          head=NULL;
          printf("Enter the data of node 1:");
          scanf("%d",&data);
          head=(struct node*)malloc(sizeof(struct node));
          if (head==NULL){
            printf("Memory allocation fails");
          }
        head->data=data;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++){
        newnode=malloc(sizeof(struct node));
        printf("Enter the data of node %d:",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
          }
        }
    } 
    //Function to display linked list
    void display(){
        if (head==NULL){
         printf("List is empty");
        }
        temp=head;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        } 
        printf("\n");
    }
    // Function to insert a node at a given position
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
        printf("The position is not valid\n");
        free(newnode);
        return;
      }  
    }
    newnode->next=temp->next;
    temp->next=newnode;
    }
}
     
    // Function to delete a node from a particular position
    void deleteatposition(){
        int pos,i;
        struct node *todelete,*prevnode;
        printf("Enter postition from which you want to delete the node:");
        scanf("%d",&pos);
        if(pos==1){
            todelete=head;
            head=head->next;
            free(todelete);
        }
        else{

            todelete=head;
            for(i=1;i<=pos && todelete!=NULL;i++){
                prevnode=todelete;
                todelete=todelete->next;

            }
            if(todelete==NULL){
                printf("Position is beyond the bounds");
            }
            prevnode->next=todelete->next;
            free(todelete);
            return;
        }

    }    
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    if (head != NULL) {
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;        
            fast = fast->next->next; 
        }
        printf("The middle node is: %d\n", slow->data);
    }
}

int main() {
    
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    
    findMiddle(head);

    return 0;
}

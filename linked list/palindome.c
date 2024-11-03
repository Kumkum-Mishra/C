#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* reverseList(struct node* head) {
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int isPalindrome(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return 1;  
    }

    struct node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node *secondHalf = reverseList(slow);
    struct node *firstHalf = head;

    struct node *copySecondHalf = secondHalf;  
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return 0;  
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    reverseList(copySecondHalf);

    return 1;  
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
   
    struct node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(1);

    printf("Original List: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is NOT a palindrome.\n");
    }

    return 0;
}

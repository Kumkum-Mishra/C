#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

struct Node* addTwoLists(struct Node* first, struct Node* second) {
    struct Node* res = NULL;
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum %= 10;
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = sum;
        temp->next = NULL;

        if (res == NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;

        if (first) first = first->next;
        if (second) second = second->next;
    }

    if (carry > 0) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = carry;
        temp->next = NULL;
        prev->next = temp;
    }
    return res;
}

void createList(struct Node** head) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            printf("Enter the value of node %d: ", i + 1);
            scanf("%d", &data);
            push(head, data);
        }
    }
}

int main() {
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* sum = NULL;

    printf("Creating the first list:\n");
    createList(&first);
    printf("First List: ");
    printList(first);

    printf("\nCreating the second list:\n");
    createList(&second);
    printf("Second List: ");
    printList(second);

    sum = addTwoLists(first, second);
    printf("\nResultant List: ");
    printList(sum);

    return 0;
}

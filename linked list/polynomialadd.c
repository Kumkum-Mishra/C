#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Function to create and append nodes to the polynomial linked list
void create_polynomial(struct Node** head) {
    int n, coeff, pow;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);

        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        newnode->coeff = coeff;
        newnode->pow = pow;
        newnode->next = NULL;

        if (*head == NULL) {
            *head = newnode;
        } else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void polyadd(struct Node* poly1, struct Node* poly2, struct Node** result) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // Dummy node to simplify head handling
    temp->next = NULL;
    *result = temp;

    while (poly1 != NULL && poly2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (poly1->pow > poly2->pow) {
            newNode->coeff = poly1->coeff;
            newNode->pow = poly1->pow;
            poly1 = poly1->next;
        } else if (poly2->pow > poly1->pow) {
            newNode->coeff = poly2->coeff;
            newNode->pow = poly2->pow;
            poly2 = poly2->next;
        } else { // Equal powers
            newNode->coeff = poly1->coeff + poly2->coeff;
            newNode->pow = poly1->pow;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }

    // Append any remaining terms from poly1 or poly2
    while (poly1 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = poly1->coeff;
        newNode->pow = poly1->pow;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = poly2->coeff;
        newNode->pow = poly2->pow;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
        poly2 = poly2->next;
    }

    // Remove dummy node
    temp = *result;
    *result = (*result)->next;
    free(temp);
}

void show(struct Node* node) {
    if (node == NULL) {
        printf("0");
        return;
    }
    while (node != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        if (node->next != NULL) {
            printf(" + ");
        }
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    printf("Enter first polynomial\n");
    create_polynomial(&poly1);
    printf("Enter second polynomial\n");
    create_polynomial(&poly2);

    printf("1st Polynomial: ");
    show(poly1);

    printf("2nd Polynomial: ");
    show(poly2);

    polyadd(poly1, poly2, &result);

    printf("Resultant Polynomial: ");
    show(result);

    return 0;
}

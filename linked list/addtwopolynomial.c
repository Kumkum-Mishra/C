#include <stdio.h>

#include <stdlib.h>

// Node structure containing power and coefficient of variable

struct Node {

int coeff;

int pow;

struct Node* next;

};

// Function to create new node

void create_node(int x, int y, struct Node** temp) {

struct Node *r, *z;// both points on first node of any polynomial

z = *temp;/// it is also pointing on the first node 

if (z == NULL) {  // checking if the node is empty or not means is there any element in the polynomial

r = (struct Node*)malloc(sizeof(struct Node));

r->coeff = x;

r->pow = y;

*temp = r;

r->next = NULL;

} else {    // adding the node at the last of the list of any polynomial

r = (struct Node*)malloc(sizeof(struct Node));

r->coeff = x;

r->pow = y;

r->next = NULL;

while (z->next != NULL) {

z = z->next;

}

z->next = r;

}

}

// Function Adding two polynomial numbers

void polyadd(struct Node* poly1, struct Node* poly2, struct Node** result) {

*result = (struct Node*)malloc(sizeof(struct Node)); // Dummy node to simplify head handling

(*result)->next = NULL;

struct Node* temp = *result;

while (poly1 != NULL && poly2 != NULL) {   // checking if list is empty or not

struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

newNode->next = NULL;

if (poly1->pow > poly2->pow) {   // checking if the pow of first first node of first polunomial is greater than the pow of first node of second polynomial
newNode->pow = poly1->pow;

newNode->coeff = poly1->coeff;

poly1 = poly1->next;

} else if (poly1->pow < poly2->pow) {   //checking if the pow of first first node of first polunomial is less than the pow of first node of second polynomial

newNode->pow = poly2->pow;

newNode->coeff = poly2->coeff;

poly2 = poly2->next;

} else {

newNode->pow = poly1->pow;  // checking for eqality of the pow of both polynomial

newNode->coeff = poly1->coeff + poly2->coeff;

poly1 = poly1->next;

poly2 = poly2->next;

}

temp->next = newNode;

temp = temp->next;

}

// Handling remaining elements

while (poly1 != NULL || poly2 != NULL) {

struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

newNode->next = NULL;

if (poly1 != NULL) {

newNode->pow = poly1->pow;

newNode->coeff = poly1->coeff;

poly1 = poly1->next;

} else if (poly2 != NULL) {

newNode->pow = poly2->pow;

newNode->coeff = poly2->coeff;

poly2 = poly2->next;

}

temp->next = newNode;

temp = temp->next;

}

// Removing the dummy node

temp = *result;

*result = (*result)->next;

free(temp);

}

// Display Linked list

void show(struct Node* node) {

while (node != NULL) {

printf("%dx^%d", node->coeff, node->pow);

node = node->next;

if (node != NULL) {

printf(" + ");

}

}

}

// Driver code

int main() {

struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

// Create first list of 5x^2 + 4x^1 + 2x^0

create_node(5, 2, &poly1);

create_node(4, 1, &poly1);

create_node(2, 0, &poly1);

// Create second list of -5x^1 - 5x^0

create_node(-5, 1, &poly2);

create_node(-5, 0, &poly2);

printf("1st Number: ");

show(poly1);

printf("\n");

printf("2nd Number: ");

show(poly2);

printf("\n");

// Function to add two polynomial numbers

polyadd(poly1, poly2, &poly);

// Display resultant List

printf("Added polynomial: ");

show(poly);

printf("\n");

return 0;

}
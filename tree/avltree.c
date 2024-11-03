#include <stdio.h>
#include <stdlib.h>

// Define the structure of an AVL tree node
struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
};

// Function to create a new AVL node
struct AVLNode* createNode(int value) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to get the height of a node
int height(struct AVLNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

// Function to get the balance factor of a node
int balanceFactor(struct AVLNode* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// Function to perform right rotation
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Function to perform left rotation
struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Function to insert a node into the AVL tree
struct AVLNode* insertNode(struct AVLNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    } else {
        // Duplicate values are not allowed in AVL tree
        return root;
    }

    // Update height of the current node
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    // Get the balance factor of the current node
    int balance = balanceFactor(root);

    // Perform rotations if needed to balance the tree
    if (balance > 1 && value < root->left->data) {
        return rightRotate(root);
    }
    if (balance < -1 && value > root->right->data) {
        return leftRotate(root);
    }
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to traverse the AVL tree in inorder
void inorderTraversal(struct AVLNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct AVLNode* root = NULL;
    int value, numNodes;

    printf("Enter the number of nodes in the AVL tree: ");
    scanf("%d", &numNodes);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Inorder traversal of the AVL tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

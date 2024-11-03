#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node and insert it into the binary tree
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        // Create a new node
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode; // Return the new node
    } else {
        if (value <= root->data) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
        return root; // Return the root of the subtree
    }
}


// Function to traverse the binary tree in inorder
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
}

// Function to traverse the binary tree in preorder
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to traverse the binary tree in postorder
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to find the minimum value node in a tree
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the binary tree
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) 
    return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct TreeNode* root = NULL;
    int value, numNodes;

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &numNodes);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal of the binary tree: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the binary tree: ");
    postorderTraversal(root);
    printf("\n");

    int keyToDelete;
    printf("Enter the value to delete from the binary tree: ");
    scanf("%d", &keyToDelete);
    root = deleteNode(root, keyToDelete);

    printf("Inorder traversal of the modified binary tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

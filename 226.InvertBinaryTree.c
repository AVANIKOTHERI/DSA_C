#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to invert (mirror) a binary tree
struct Node* invertTree(struct Node* root) {
    if (root == NULL)
        return NULL;

    // Swap left and right subtrees
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively invert left and right subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// Function to print Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Driver code
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Inorder Traversal Before Inversion: ");
    inorder(root);
    printf("\n");

    root = invertTree(root);

    printf("Inorder Traversal After Inversion: ");
    inorder(root);
    printf("\n");

    return 0;
}

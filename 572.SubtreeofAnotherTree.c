#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to check if two trees are identical
bool isIdentical(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;  // Both trees are empty, so they are identical

    if (root1 == NULL || root2 == NULL)
        return false; // One tree is empty and the other is not

    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// Function to check if T2 is a subtree of T1
bool isSubtree(struct Node* T1, struct Node* T2) {
    if (T2 == NULL)
        return true;  // An empty tree is always a subtree

    if (T1 == NULL)
        return false; // If T1 is empty but T2 is not, T2 cannot be a subtree

    // If T1 and T2 are identical, return true
    if (isIdentical(T1, T2))
        return true;

    // Otherwise, check in the left and right subtrees
    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

// Driver code
int main() {
    // Construct Tree T1
    struct Node* T1 = createNode(50);
    T1->left = createNode(30);
    T1->right = createNode(70);
    T1->left->left = createNode(20);
    T1->left->right = createNode(40);
    T1->right->left = createNode(60);
    T1->right->right = createNode(80);

    // Construct Tree T2 (which is a subtree of T1)
    struct Node* T2 = createNode(30);
    T2->left = createNode(20);
    T2->right = createNode(40);

    if (isSubtree(T1, T2))
        printf("T2 is a subtree of T1\n");
    else
        printf("T2 is NOT a subtree of T1\n");

    return 0;
}

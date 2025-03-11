#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to detect a loop in a linked list
int detectLoop(struct Node* head) {
    struct Node *slowPtr = head, *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;         // Move slow pointer by 1 step
        fastPtr = fastPtr->next->next;   // Move fast pointer by 2 steps

        if (slowPtr == fastPtr) {  // If they meet, a loop exists
            return 1;  // Loop detected
        }
    }
    return 0;  // No loop
}

// Function to insert a node at the beginning
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to create a loop in the linked list (for testing)
void createLoop(struct Node* head, int position) {
    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }
    if (loopNode) {
        temp->next = loopNode; // Creating the loop
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtHead(&head, 5);
    insertAtHead(&head, 4);
    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);

    // Creating a loop for testing
    createLoop(head, 3);  // Loop at position 3 (Node with value 3)

    if (detectLoop(head))
        printf("Loop detected in th

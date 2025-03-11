struct Node* removeNthFromEnd(struct Node* head, int N) {
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node *fast = dummy, *slow = dummy;

    // Move fast pointer N+1 steps ahead
    for (int i = 0; i <= N; i++) {
        if (fast == NULL) return head;  // If N is greater than the length of the list
        fast = fast->next;
    }

    // Move both slow and fast one step at a time
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete the Nth node from end
    struct Node* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    struct Node* newHead = dummy->next;
    free(dummy);
    return newHead;
}

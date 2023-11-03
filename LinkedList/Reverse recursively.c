#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to reverse the linked list
Node* reverseListRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;  // Base case: empty list or single node list
    }

    Node* rest = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Original Linked List: ");
    displayList(head);

    head = reverseListRecursive(head);

    printf("Reversed Linked List: ");
    displayList(head);

    // Free the allocated memory (optional, for completeness)
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
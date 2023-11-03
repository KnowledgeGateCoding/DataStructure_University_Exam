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

// Function to search for a key in the linked list iteratively
Node* searchKeyIterative(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current; // Key found
        }
        current = current->next;
    }
    return NULL; // Key not found
}

int main() {
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    int key = 20;
    Node* result = searchKeyIterative(head, key);
    if (result) {
        printf("Key %d found in the linked list.\n", key);
    } else {
        printf("Key %d not found in the linked list.\n", key);
    }

    // Free the allocated memory (optional, for completeness)
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
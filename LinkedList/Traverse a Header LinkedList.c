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

// Function to insert a node at the end of the header linked list
void insertEnd(Node* header, int data) {
    Node* newNode = createNode(data);
    Node* temp = header;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to traverse the header linked list
void traverseHeaderLinkedList(Node* header) {
    if (header == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = header->next;  // Start from the node after header
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a header node
    Node* header = createNode(-1);  // The data inside header doesn't represent actual data

    insertEnd(header, 10);
    insertEnd(header, 20);
    insertEnd(header, 30);

    printf("Header Linked List: ");
    traverseHeaderLinkedList(header);

    // Free the allocated memory (optional, for completeness)
    while (header) {
        Node* temp = header;
        header = header->next;
        free(temp);
    }

    return 0;
}
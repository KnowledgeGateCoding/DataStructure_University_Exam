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
    newNode->next = newNode;  // Initialize as circular by default
    return newNode;
}

// Function to insert a node at the end of the header circular linked list
void insertEnd(Node* header, int data) {
    Node* newNode = createNode(data);
    Node* temp = header;
    while (temp->next != header) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = header;  // Point back to header to maintain circularity
}

// Function to traverse the header circular linked list
void traverseHeaderCircularLinkedList(Node* header) {
    if (header->next == header) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = header->next;  // Start from the first node after the header
    while (temp != header) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("HEADER\n");  // To signify the circular nature and return to header
}

int main() {
    // Create a header node
    Node* header = createNode(-1);  // The data inside header doesn't represent actual data

    insertEnd(header, 10);
    insertEnd(header, 20);
    insertEnd(header, 30);

    printf("Header Circular Linked List: ");
    traverseHeaderCircularLinkedList(header);

    // Free the allocated memory (optional, for completeness)
    Node* temp = header;
    do {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != header);

    return 0;
}

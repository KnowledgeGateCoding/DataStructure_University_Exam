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

// Function to insert a node after a specified location
void insertAfter(Node* prevNode, int key) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }

    Node* newNode = createNode(key);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
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
    head->next->next = createNode(40); // 10 -> 20 -> 40

    insertAfter(head->next, 30); // Insert 30 after 20
    // Resulting list: 10 -> 20 -> 30 -> 40

    printf("Linked List: ");
    displayList(head);

    // Free the allocated memory (optional, for completeness)
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

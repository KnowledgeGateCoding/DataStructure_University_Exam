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

// Function to delete the first node of the linked list
void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
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

    printf("Original Linked List: ");
    displayList(head);

    deleteAtBeginning(&head);

    printf("Linked List after deletion: ");
    displayList(head);

    // Free the remaining allocated memory (for completeness)
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
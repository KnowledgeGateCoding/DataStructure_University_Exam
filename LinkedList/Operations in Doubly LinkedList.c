#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Traversal
void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search for an element
Node* search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;  // Key not found
}

// Delete at the beginning
void deleteAtBeginning(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Delete at the end
void deleteAtEnd(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

// Delete node at a specific location
void deleteAtSpecificLocation(Node** head, int position) {
    if (*head == NULL || position < 1) return;

    Node* temp = *head;
    int count = 1;
    while (count < position && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) return;  // Position out of bounds

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("Doubly Linked List after Insertions: ");
    traverse(head);

    Node* searchResult = search(head, 30);
    if (searchResult) {
        printf("Element 30 found.\n");
    } else {
        printf("Element 30 not found.\n");
    }

    deleteAtBeginning(&head);
    printf("Doubly Linked List after deleting at beginning: ");
    traverse(head);

    deleteAtEnd(&head);
    printf("Doubly Linked List after deleting at end: ");
    traverse(head);

    deleteAtSpecificLocation(&head, 2);  // Deleting the node at position 2
    printf("Doubly Linked List after deleting at position 2: ");
    traverse(head);

    return 0;
}
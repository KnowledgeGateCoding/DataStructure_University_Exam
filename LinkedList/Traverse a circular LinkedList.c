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

// Function to insert a node at the end of the circular linked list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to traverse the circular linked list
void traverseCircularLinkedList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d (head)\n", head->data);  // To signify the circular nature
}

int main() {
    Node* head = NULL;  // Initialize an empty circular linked list

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("Circular Linked List: ");
    traverseCircularLinkedList(head);

    // Free the allocated memory (optional, for completeness)
    Node* temp = head;
    if (temp != NULL) {
        Node* start = temp;
        do {
            Node* nextNode = temp->next;
            free(temp);
            temp = nextNode;
        } while (temp != start);
    }

    return 0;
}
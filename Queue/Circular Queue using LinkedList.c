#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the CircularQueue structure
typedef struct {
    Node* front;
    Node* rear;
} CircularQueue;

// Initialize the circular queue
void initialize(CircularQueue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(CircularQueue* q) {
    return q->front == NULL;
}

// Enqueue an item to the queue
void enqueue(CircularQueue* q, int item) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Queue overflow!\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        newNode->next = newNode; // point to itself as it's the only node
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue an item from the queue
int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        exit(1);
    }
    Node* temp = q->front;
    int dequeuedItem = temp->data;

    if (q->front == q->rear) {
        // Only one item in the queue
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }
    free(temp);
    return dequeuedItem;
}

int main() {
    CircularQueue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued element: %d\n", dequeue(&q));  // Should print 10
    printf("Dequeued element: %d\n", dequeue(&q));  // Should print 20

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("Dequeued element: %d\n", dequeue(&q));  // Should print 30
    printf("Dequeued element: %d\n", dequeue(&q));  // Should print 40

    return 0;
}
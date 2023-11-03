#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Initialize the queue
void initialize(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Enqueue an item to the queue
void enqueue(Queue* q, int item) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Queue overflow!\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

// Dequeue an item from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        exit(1);
    }
    Node* temp = q->front;
    int dequeuedItem = temp->data;
    q->front = q->front->next;

    // If the dequeued item was the last item in the queue, update the rear pointer
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedItem;
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued element: %d\n", dequeue(&q)); // Should print 10
    printf("Dequeued element: %d\n", dequeue(&q)); // Should print 20

    return 0;
}

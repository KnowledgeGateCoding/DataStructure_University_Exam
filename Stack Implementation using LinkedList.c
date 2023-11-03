#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Stack structure
typedef struct {
    Node* top;
} Stack;

// Initialize the stack
void initialize(Stack* s) {
    s->top = NULL;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Push an item onto the stack
void push(Stack* s, int item) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack overflow!\n");
        exit(1); // Exit with an error code
    }
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop an item from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        exit(1); // Exit with an error code
    }
    Node* temp = s->top;
    int poppedData = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedData;
}

// Peek the top item without removing it
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1); // Exit with an error code
    }
    return s->top->data;
}

int main() {
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s)); // Should print 30

    printf("Popped element: %d\n", pop(&s)); // Should print 30
    printf("Popped element: %d\n", pop(&s)); // Should print 20

    return 0;
}

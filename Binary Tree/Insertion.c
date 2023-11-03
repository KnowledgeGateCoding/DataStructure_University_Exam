#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
void insertBST(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    
    if (data < (*root)->data) {
        insertBST(&((*root)->left), data);
    } else if (data > (*root)->data) {
        insertBST(&((*root)->right), data);
    } else {
        // If data is equal to the current node's data, we won't insert it
        // to avoid duplicate entries. Alternatively, you can handle duplicates
        // as per your requirements.
        printf("Element %d already exists in the BST.\n", data);
    }
}

int main() {
    Node* root = NULL;

    insertBST(&root, 50);
    insertBST(&root, 30);
    insertBST(&root, 70);
    insertBST(&root, 20);
    insertBST(&root, 40);
    insertBST(&root, 60);
    insertBST(&root, 80);

    // You can add any other functions or logic as needed.

    return 0;
}
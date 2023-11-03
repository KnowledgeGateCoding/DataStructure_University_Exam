#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertBST(Node* root, int data) {
    if (root == NULL) return createNode(data);
    
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }
    
    return root;
}

// Function to search for an element in a BST
Node* searchBST(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchBST(root->left, data);
    }

    return searchBST(root->right, data);
}

int main() {
    Node* root = NULL;
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 70);
    root = insertBST(root, 60);
    root = insertBST(root, 80);

    int searchElement = 25;
    Node* searchResult = searchBST(root, searchElement);

    if (searchResult) {
        printf("Element %d found in the BST.\n", searchElement);
    } else {
        printf("Element %d not found in the BST.\n", searchElement);
    }

    return 0;
}
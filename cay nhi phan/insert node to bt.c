#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    // Create a queue to perform level order traversal
    Node* queue[100];
    int front = -1;
    int rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        Node* temp = queue[++front];

        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        } else {
            temp->left = createNode(data);
            return root;
        }

        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        } else {
            temp->right = createNode(data);
            return root;
        }
    }

    return root;
}

// Function to print the binary tree in level order traversal
void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    // Create a queue to perform level order traversal
    Node* queue[100];
    int front = -1;
    int rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        Node* temp = queue[++front];

        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[++rear] = temp->left;

        if (temp->right != NULL)
            queue[++rear] = temp->right;
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(6);

    printf("Binary tree before adding a node: ");
    levelOrderTraversal(root);
    printf("\n");

    int newNodeValue = 7;
    root = insertNode(root, newNodeValue);

    printf("Binary tree after adding a node: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}

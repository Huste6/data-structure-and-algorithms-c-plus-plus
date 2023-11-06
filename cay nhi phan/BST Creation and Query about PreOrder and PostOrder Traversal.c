#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BST {
    int data;
    struct BST* left;
    struct BST* right;
} BST;

BST* insert(BST* root, int x) {
    if (root == NULL) {
        BST* newNode = (BST*)malloc(sizeof(BST));
        newNode->data = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    } else {
        if (root->data > x) {
            root->left = insert(root->left, x);
        } else if (root->data < x) {
            root->right = insert(root->right, x);
        }
    }
    return root;
}

void preOrder(BST* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(BST* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    char s[100];
    int n;
    BST* root = NULL;

    while (scanf("%s", s) == 1) {
        if (strcmp(s, "insert") == 0) {
            scanf("%d", &n);
            root = insert(root, n);
        } else if (strcmp(s, "preorder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(s, "postorder") == 0) {
            postOrder(root);
            printf("\n");
        } else if (strcmp(s, "#") == 0) {
            break;
        }
    }
    return 0;
}

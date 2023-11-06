#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* make_treeNode(int x) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
TreeNode* findNode(TreeNode* root, int id) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == id) {
        return root;
    }
    TreeNode* leftResult = findNode(root->left, id);
    if (leftResult != NULL) {
        return leftResult;
    }
    TreeNode* rightResult = findNode(root->right, id);
    return rightResult;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int isBalanced(TreeNode* root) {
    if (root == NULL) {
        return 1;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return 1;
    }
    return 0;
}

int main() {
    TreeNode* root = NULL;
    char str[100];
    int u, v;
    while (1) {
        scanf("%s", str);
        if (strcmp(str, "MakeRoot") == 0) {
            scanf("%d", &v);
            root = make_treeNode(v);
        }
        else if (strcmp(str, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            TreeNode*parent=findNode(root,v);
            parent->left=make_treeNode(u);
        }
        else if (strcmp(str, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            TreeNode*parent=findNode(root,v);
            parent->right=make_treeNode(u);
        }
        else if (strcmp(str, "*") == 0) break;
    }
    if (isBalanced(root)==1)
        printf("1 ");
    else
        printf("0 ");
    printf("%d ", getHeight(root));
    return 0;
}

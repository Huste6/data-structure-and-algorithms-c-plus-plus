#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

int height(TreeNode* node){
    if(node == NULL)
        return 0;
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);

        return max(lheight, rheight) + 1;
    }
}

void printCurrentLevel(TreeNode* node, int level){
    if(node == NULL)
        return;

    if(level == 1){
        cout << node->data << " ";
    }
    else if(level > 1){
        printCurrentLevel(node->left, level - 1);
        printCurrentLevel(node->right, level - 1);
    }
}

void printLevelOrder(TreeNode* node){
    int h = height(node);
    for(int i = 1; i <= h; i++){
        printCurrentLevel(node, i);
    }
}

void printLevelOrder1(TreeNode* node){
    if(node == NULL){
        return;
    }

    queue<TreeNode*> q;
    q.push(node);

    while(q.empty() == false){
        TreeNode* currNode = q.front();
        cout << currNode->data << " ";
        q.pop();

        if(currNode->left != NULL){
            q.push(currNode->left);
        }

        if(currNode->right != NULL){
            q.push(currNode->right);
        }
    }
}

TreeNode* newNode(int data){
    TreeNode* Node = new TreeNode();
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}
// Helper function to print nodes at a given level
void printGivenLevel(TreeNode* root, int level, bool ltr) {
    if(root == NULL) return;
    if(level == 1){
        cout << root->data << " ";
    } else if(level > 1){
        if(ltr){
            printGivenLevel(root->left, level-1, ltr);
            printGivenLevel(root->right, level-1, ltr);
        } else{
            printGivenLevel(root->right, level-1, ltr);
            printGivenLevel(root->left, level-1, ltr);
        }
    }
}
// Function to print spiral traversal of a tree
void printSpiral(TreeNode* root) {
    int h = height(root);
    bool ltr = false;
    for(int i = 1; i <= h; i++){
        // In theo tung level
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
    }
}

int main(){
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree using printLevelOrder:\n";
    printLevelOrder(root);

    cout << "\nLevel Order traversal of binary tree using printLevelOrder1:\n";
    printLevelOrder1(root);

    cout << "\nLevel order traversal in spiral form:\n";
    printSpiral(root);
    return 0;
}

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
//Level order traversal of Binary Tree in Spiral form Using Stack
void printSpiral1(TreeNode*root)
{
    if(root==NULL) return;
    stack<TreeNode*> s1;//for level to be print right to left
    stack<TreeNode*> s2;//for level to be print left to right
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty()){
            TreeNode*tmp=s1.top();
            s1.pop();
            cout<<tmp->data<<" ";
            if(tmp->right) s2.push(tmp->right);
            if(tmp->left) s2.push(tmp->left);
        }
        while(!s2.empty()){
            TreeNode*tmp=s2.top();s2.pop();cout<<tmp->data<<" ";
            if(tmp->left) s1.push(tmp->left);
            if(tmp->right) s1.push(tmp->right);
        }
    }
}
//reverse level order traversal
void reverseTraversal(TreeNode*root)
{
    int h=height(root);
    for(int i=h;i>=1;i--){
        printCurrentLevel(root,i);
    }
}
//reverse level order traversal using stack and queue
void reverseTraversal1(TreeNode*root)
{
    stack<TreeNode*> s;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode*tmp=q.front();q.pop();s.push(tmp);
        if(tmp->right) q.push(tmp->right);
        if(tmp->left) q.push(tmp->left);
    }
    while(!s.empty()){
        TreeNode*tmp=s.top();s.pop();cout<<tmp->data<<" ";
    }
}
void preorder(struct TreeNode* root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<"in theo preorder: \n";preorder(root);

    cout << "\nLevel Order traversal of binary tree using printLevelOrder:\n";
    printLevelOrder(root);

    cout << "\nLevel Order traversal of binary tree using printLevelOrder1:\n";
    printLevelOrder1(root);

    cout << "\nLevel order traversal in spiral form:\n";
    printSpiral(root);

    cout << "\nLevel order traversal in spiral form using stack:\n";
    printSpiral1(root);

    cout << "\nReverse level Order traversal of binary tree using reverseTraversal:\n";
    reverseTraversal(root);

    cout << "\nReverse level Order traversal of binary tree using stack and queue:\n";
    reverseTraversal1(root);
    return 0;
}

#include<iostream>
#include<queue>
using namespace std;
struct TreeNode{
    int data;
    TreeNode*left,*right;
};
TreeNode*createNode(int data)
{
    TreeNode*newnode=new TreeNode();
    if(!newnode)
    {
        cout<<"Memory errol!";return NULL;
    }
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
TreeNode*insertNode(TreeNode*node,int data)
{
    if(node==NULL){
        node=createNode(data);
        return node;
    }
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty()){
        TreeNode*tmp=q.front();q.pop();
        if(tmp->left!=NULL){
            q.push(tmp->left);
        }else{
            tmp->left=createNode(data);
            return node;
        }
        if(tmp->right!=NULL){
            q.push(tmp->right);
        }else{
            tmp->right=createNode(data);
            return node;
        }
    }
}
void inorder(TreeNode*node)
{
    if(node==NULL) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
int main()
{
    TreeNode* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 12;
    root = insertNode(root, key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}

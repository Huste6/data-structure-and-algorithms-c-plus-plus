#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode*left,*right;
};
void inorder(TreeNode*node)
{
    if(node==NULL) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
void deleteDeepthNode(TreeNode*node,TreeNode*d_node)
{
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty()){
        TreeNode*tmp=q.front();q.pop();
        if(tmp==d_node){
            tmp=NULL;
            delete(d_node);return;
        }
        if(tmp->right){
            if(tmp->right==d_node){
                tmp->right=NULL;
                delete(d_node);
                return;
            }
        }
        if(tmp->left){
            if(tmp->left==d_node){
                tmp->left=NULL;
                delete(d_node);
                return;
            }
        }
    }
}
TreeNode*deletion(TreeNode*node,int key)
{
    if(node==NULL) return NULL;
    if(node->left==NULL && node->right==NULL)
    {
        if(node->data==key)
        {
            return NULL;
        }else{
            return node;
        }
    }
    queue<TreeNode*> q;
    q.push(node);
    TreeNode*tmp=NULL;
    TreeNode*key_node=NULL;
    while(!q.empty()){
        tmp=q.front();q.pop();
        if(tmp->data==key){
            key_node=tmp;
        }
        if(tmp->left){
            q.push(tmp->left);
        }
        if(tmp->right){
            q.push(tmp->right);
        }
    }
    //con tro tmp nam o cuoi
    if(key_node!=NULL){
        int x=tmp->data;

        key_node->data=x;
    }
    return node;
}
TreeNode*newNode(int data)
{
    TreeNode*tmp=new TreeNode();
    tmp->data=data;
    tmp->left=tmp->right=NULL;
    return tmp;
}
int main()
{
    struct TreeNode* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    cout << "Inorder traversal before deletion: ";
    inorder(root);

    int key = 11;
    root = deletion(root, key);

    cout << endl;
    cout << "Inorder traversal after deletion: ";
    inorder(root);

    return 0;
}

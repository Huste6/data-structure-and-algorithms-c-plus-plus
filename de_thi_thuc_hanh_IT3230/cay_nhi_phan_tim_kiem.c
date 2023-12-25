#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    int data;
    struct TreeNode*left;
    struct TreeNode*right;
}TreeNode;
TreeNode*root=NULL;
TreeNode*makeTree(int val)
{
    TreeNode*newnode=(TreeNode*)malloc(sizeof(TreeNode));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
TreeNode*insert(TreeNode*root,int val)
{
    if(root==NULL){
        TreeNode*tmp=makeTree(val);
        return tmp;
    }
    if(root->data>val){
        root->left=insert(root->left,val);
    }else if(root->data<val)
    {
        root->right=insert(root->right,val);
    }
    return root;
}
TreeNode*find(TreeNode*root,int val)
{
    if(root==NULL) return NULL;
    if(root->data==val) return root;
    TreeNode*tmp=find(root->left,val);
    if(tmp!=NULL) return tmp;
    return find(root->right,val);
}
void destroyTree(TreeNode*root)
{
    if(root!=NULL){
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}
void xulyfile(char*filename)
{
    FILE*f=fopen(filename,"r");
    int n;fscanf(f,"%d\n",&n);
    int a[n];
    for(int i=0;i<n;i++){
        fscanf(f,"%d ",&a[i]);
        root=insert(root,a[i]);
    }
    fclose(f);
}
void inorder(TreeNode*root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void node_co_2_con(TreeNode*root)
{
    if(root!=NULL){
        if(root->left!=NULL && root->right!=NULL) printf("%d ",root->data);
        node_co_2_con(root->left);
        node_co_2_con(root->right);
    }
}
void node_co_1_con(TreeNode*root)
{
    if(root!=NULL){
        if((root->left!=NULL && root->right==NULL) || (root->right!=NULL && root->left==NULL)) printf("%d ",root->data);
        node_co_1_con(root->left);
        node_co_1_con(root->right);
    }
}
void node_la(TreeNode*root)
{
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL) printf("%d ",root->data);
        node_co_2_con(root->left);
        node_co_2_con(root->right);
    }
}
int timmax(TreeNode*root)
{
    if(root->left==NULL && root->right==NULL) return root->data;
    int max=root->data;
    if(root->right!=NULL){
        int max1=timmax(root->right);
        if(max1>max) max=max1;
    }
    return max;
}
void XoaNode(TreeNode** root, TreeNode* tmp) {
    if (*root == NULL)
        return;

    if (tmp->data< (*root)->data) {
        XoaNode(&(*root)->left, tmp);
    }
    else if (tmp->data> (*root)->data) {
        XoaNode(&(*root)->right, tmp);
    }
    else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left == NULL) {
            TreeNode* temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL) {
            TreeNode* temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else {
            TreeNode* minRight = (*root)->right;
            while (minRight->left != NULL)
                minRight = minRight->left;

            (*root)->data = minRight->data;
            XoaNode(&(*root)->right, minRight);
        }
    }
}
int main()
{
    xulyfile("input.txt");
    while(1){
        printf("-------------------------\n");
        printf("1.in cay\n");
        printf("2.tim kiem\n");
        printf("3.Node co 2 con\n");
        printf("4.Node co 1 con\n");
        printf("5.Node la\n");
        printf("6.Node co gia tri max\n");
        printf("7.Xoa 1 node bat ki\n");
        printf("-------------------------\n");
        int cmd;scanf("%d",&cmd);
        if(cmd==1){
            inorder(root);
            printf("\n");
        }else if(cmd==2){
            printf("Nhap so can tim kiem: ");
            int val;scanf("%d",&val);
            TreeNode*tmp=find(root,val);
            if(tmp==NULL) printf("Not Found!\n");
            else printf("Found!\n");
        }else if(cmd==3){
            node_co_2_con(root);
            printf("\n");
        }else if(cmd==4){
            node_co_1_con(root);
            printf("\n");
        }else if(cmd==5){
            node_la(root);
            printf("\n");
        }else if(cmd==6){
            printf("%d",timmax(root));
            printf("\n");
        }
        else if(cmd==7){
            printf("nhap node can xoa: ");
            int val;scanf("%d",&val);
            TreeNode*tmp=makeTree(val);
            if(tmp==NULL) printf("Not Found!\n");
            else{
                XoaNode(&root,tmp);
                inorder(root);
                printf("\n");
            }
        }
        else break;
    }
    destroyTree(root);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void inorder(struct node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct node* create(int a) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = a;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* add_left_node(struct node* root, int a) {
    root->left = create(a);
    return root->left;
}

struct node* add_right_node(struct node* root, int a) {
    root->right = create(a);
    return root->right;
}

int maxDepth(struct node* root) {
    if(root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right) ? left + 1 : right + 1;
}
struct node*find(struct node* root,int val)
{
    if(root==NULL) return NULL;
    if(root->data==val) return val;
    struct node*tmp=find(root->left,val);
    if(tmp!=NULL) return tmp;
    return find(root->right,val);
}
int main() {
    struct node* root = create(34);
    add_left_node(root, 32);
    add_left_node(root->left, 42);
    add_right_node(root->left, 93);

    printf("Duyet theo cach Inorder\n");
    inorder(root);

    printf("\nDuyet theo cach Preorder\n");
    preorder(root);

    printf("\nDuyet theo cach Postorder\n");
    postorder(root);

    printf("\nDo sau lon nhat tu root den la: %d\n", maxDepth(root));
    struct node*tmp=find(root,42);
    if(tmp!=NULL) printf("Found\n");
    else printf("Not Found\n");
    return 0;
}

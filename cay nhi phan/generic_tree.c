#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    int data;
    struct Node *firstChild;
    struct Node *nextSibling;
} Node;

Node *makeNode(int x) {
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = x;
    tmp->firstChild = NULL;
    tmp->nextSibling = NULL;
    return tmp;
}

void insert(struct Node *parent, int val) {
    struct Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;

    if (parent->firstChild == NULL) {
        parent->firstChild = newNode;
    } else {
        struct Node *sibling = parent->firstChild;
        while (sibling->nextSibling != NULL) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = newNode;
    }
}

Node *findNode(struct Node *root, int val) {
    if (root == NULL) return NULL;
    if (root->data == val) return root;
    Node *tmp = findNode(root->firstChild, val);
    if (tmp != NULL) return tmp;
    Node *tmp1 = findNode(root->nextSibling, val);
    return tmp1;
}

void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    Node*p=root->firstChild;
    while(p!=NULL){
        preOrder(p);
        p=p->nextSibling;
    }
}

void postOrder(Node *root) {
    if (root == NULL) return;
    Node*p=root->firstChild;
    while(p!=NULL){
        postOrder(p);
        p=p->nextSibling;
    }
    printf("%d ",root->data);
}

void inOrder(Node *root) {
    if (root == NULL) return;
    Node*p=root->firstChild;
    inOrder(p);
    printf("%d ",root->data);
    if(p!=NULL) p=p->nextSibling;
    while(p!=NULL){
        inOrder(p);
        p=p->nextSibling;
    }
}

int main() {
    Node *root = NULL;
    char s[100];
    int u, v;
    while (scanf("%s", s) == 1) {
        if (strcmp(s, "MakeRoot") == 0) {
            scanf("%d", &v);
            root = makeNode(v);
        } else if (strcmp(s, "Insert") == 0) {
            scanf("%d%d", &u, &v);
            Node *tmp = findNode(root, v);
            if (tmp != NULL) {
                insert(tmp, u);
            }
        } else if (strcmp(s, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(s, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(s, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        } else if (strcmp(s, "*") == 0) {
            break;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* leftMostChild;
    struct Node* rightSibling;
} Node;

Node* root;

Node* makeNode(int x) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = x;
    tmp->leftMostChild = NULL;
    tmp->rightSibling = NULL;
    return tmp;
}

Node* find(Node* r, int x) {
    if (r == NULL) return NULL;
    if (r->data == x) return r;
    Node* p = r->leftMostChild;
    while (p != NULL) {
        Node* q = find(p, x);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

Node* addLast(Node* p, int x) {
    if (p == NULL) return makeNode(x);
    p->rightSibling = addLast(p->rightSibling, x);
    return p;
}

void addChild(int x, int y) {
    Node* r = find(root, x);
    if (r == NULL) return;
    r->leftMostChild = addLast(r->leftMostChild, y);
}

bool check_node_con_chan(int x) {
    Node* tmp = find(root, x);
    if (tmp == NULL) return false;
    int cnt = 0;
    Node* p = tmp->leftMostChild;
    if(p==NULL) return false;
    while (p != NULL) {
        cnt++;
        p = p->rightSibling;
    }
    if (cnt % 2 == 0 && cnt!=0) return true;
    else return false;
}

bool check_nut(int x) {
    Node* tmp = find(root, x);
    if (tmp == NULL) return false;
    Node* p = tmp->leftMostChild;
    while (p != NULL) {
        if (check_node_con_chan(p->data) == false) return false;
        p = p->rightSibling;
    }
    return true;
}

int cnt_check(Node* r) {
    if (r == NULL) return 0;
    int cnt = 0;
    if (check_nut(r->data)==true && r->leftMostChild!=NULL){
        cnt=1;
    }
    Node* p = r->leftMostChild;
    while (p != NULL) {
        cnt += cnt_check(p);
        p = p->rightSibling;
    }
    return cnt;
}

void printTree(Node* r) {
    if (r == NULL) return;
    printf("%d: ", r->data);
    Node* p = r->leftMostChild;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->rightSibling;
    }
    printf("\n");
    p = r->leftMostChild;
    while (p != NULL) {
        printTree(p);
        p = p->rightSibling;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    int data;
    scanf("%d", &data);
    root = makeNode(data);
    int k1;scanf("%d",&k1);
    for(int i=0;i<k1;i++){
        int x1;scanf("%d",&x1);
        addChild(data,x1);
    }
    for (int i = 1; i < n; i++) {
        int parent, childCount;
        scanf("%d%d", &parent, &childCount);
        for (int j = 0; j < childCount; j++) {
            scanf("%d", &data);
            addChild(parent, data);
        }
    }
    printf("%d\n",cnt_check(root));
    return 0;
}



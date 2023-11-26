#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* leftmostchild;
    struct node* rightsibling;
} node;
node* root;node*prev=NULL;
node* makenode(int x) {
    node* tmp = (node*)malloc(sizeof(node));
    tmp->data = x;
    tmp->leftmostchild = NULL;
    tmp->rightsibling = NULL;
    return tmp;
}

node* find(node* r, int x) {
    if (r == NULL) return NULL;
    if (r->data == x) return r;
    node* tmp = r->leftmostchild;
    while (tmp != NULL) {
        node* tmp1 = find(tmp, x);
        if (tmp1 != NULL) return tmp1;
        tmp = tmp->rightsibling;
    }
    return NULL;
}

node* addLast(node* p, int x) {
    if (p == NULL) return makenode(x);
    p->rightsibling = addLast(p->rightsibling, x);
    return p;
}

void addChild(int x, int y) {
    node* r = find(root, x);
    if (r == NULL) return;
    r->leftmostchild = addLast(r->leftmostchild, y);
}

int cnt_greater(node* r, int x) {
    if (r == NULL) return 0;
    int cnt=0;
    if (r->data > x) cnt = 1;
    node* tmp = r->leftmostchild;
    while (tmp != NULL) {
        cnt += cnt_greater(tmp, x);
        tmp = tmp->rightsibling;
    }
    return cnt;
}

bool check_la(node* r) {
    node* p = r->leftmostchild;
    if (p == NULL)
        return true;
    return false;
}

void printtree(node* r){
    if(r == NULL)
        return;
    if(check_la(r)==false){
        printf("%d: ",r->data);
        node* p = r->leftmostchild;
        while(p != NULL){
            printf("%d ",p->data);
            p = p->rightsibling;
        }
        printf("\n");
        p = r->leftmostchild;
        while(p != NULL){
            printtree(p);
            p = p->rightsibling;
        }
    }
}

void freetree(node* r){
    if(r == NULL)
        return;
    node* p = r->leftmostchild;
    while(p != NULL){
        node* sp = p->rightsibling;
        freetree(p);
        p = sp;
    }
    free(r);
    r = NULL;
}

int height(node* r) {
    if(r == NULL)
        return 0;

    int maxh = 0;
    node* tmp = r->leftmostchild;
    while(tmp != NULL) {
        int h = height(tmp);
        if(h > maxh)
            maxh = h;
        tmp = tmp->rightsibling;
    }
    return maxh + 1;
}
//duyet theo level
void in_tai_1_level(node* r, int level) {
    if(r == NULL)
        return;
    if(level == 1) {
        printf("%d ", r->data);
        return;
    }
    node* tmp = r->leftmostchild;
    while(tmp != NULL) {
        in_tai_1_level(tmp, level - 1);
        tmp = tmp->rightsibling;
    }
}

void duyet_theo_level(node* r) {
    if (r == NULL)
        return;
    for (int i = 1; i <= height(r); i++) {
        in_tai_1_level(r, i);
        printf("\n");
    }
}
//in ra cac node la
void in_la(node* r)
{
    if (r == NULL) return;
    if (r->leftmostchild == NULL) {
        printf("%d ", r->data);
    }
    node* tmp = r->leftmostchild;
    while (tmp != NULL) {
        in_la(tmp);
        tmp = tmp->rightsibling;
    }
}
//xoa cac node la
void delete_leaf(node* r)
{
    if (r == NULL) return;
    if (r->leftmostchild == NULL) {
        free(r);
        return;
    }
    node* tmp = r->leftmostchild;
    node* prev = NULL;
    while (tmp != NULL) {
        if (check_la(tmp)) {
            if (prev == NULL) {
                // First child of the parent is a leaf
                r->leftmostchild = tmp->rightsibling;
            } else {
                // Not the first child, update the previous sibling's rightsibling
                prev->rightsibling = tmp->rightsibling;
            }
            node* next = tmp->rightsibling;
            free(tmp);
            tmp = next;
        } else {
            // Recursive call to delete leaf nodes from the child
            //goi den la
            delete_leaf(tmp);
            prev = tmp;
            tmp = tmp->rightsibling;
        }
    }
}
//xoa tat ca cac con cua node do
void xoa_tat_ca_con(node*r)
{
    if(r==NULL) return;
    node*child=r->leftmostchild;
    while(child!=NULL){
        node*nextSibling=child->rightsibling;
        xoa_tat_ca_con(child);
        free(child);
        child=nextSibling;
    }
    r->leftmostchild=NULL;
}


int main() {
    char s[100];
    int x, y;
    while (1) {
        scanf("%s", s);
        if (strcmp(s, "makeroot") == 0) {
            scanf("%d", &x);
            root = makenode(x);
        } else if (strcmp(s, "insert") == 0) {
            scanf("%d%d", &y, &x);
            addChild(x,y);
        } else if (strcmp(s, "print") == 0) {
            printtree(root);
        } else if (strcmp(s, "node_lon_hon") == 0) {
            scanf("%d", &x);
            printf("so nut lon hon %d la: %d\n", x, cnt_greater(root, x));
        }else if(strcmp(s,"duyet_theo_level")==0){
            duyet_theo_level(root);
        }else if(strcmp(s,"in_la")==0){
            in_la(root);
            printf("\n");
        }else if(strcmp(s,"xoa_cac_node_la")==0){
            delete_leaf(root);
            printtree(root);
        }else if(strcmp(s,"xoa_cac_node_con")==0){
            scanf("%d",&x);
            node*r=find(root,x);
            if(r!=NULL){
                xoa_tat_ca_con(r);
                printtree(root);
            }
            else printf("ko tim thay %d",x);
        //xoa 1 nut bat ki dong thoi xoa luon con cua node do
        }else if(strcmp(s,"xoa_1_nut_bat_ki_vao_con")==0){
            scanf("%d",&x);
            node*r=find(root,x);
            if(r!=NULL){
                xoa_tat_ca_con_1(root,r);
                printtree(root);
            }else{
                printf("ko tim thay %d",x);
            }
        }
        else if (strcmp(s, "**") == 0)
            break;
    }
    freetree(root);
    return 0;
}

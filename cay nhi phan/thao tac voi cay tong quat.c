#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct Node{
    char name[256];
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Node;
Node* root;
Node* makeNode(char* name){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name);
    p->leftMostChild = NULL; p->rightSibling = NULL;
    return p;
}
Node* find(Node* r, char* name){
    if(r == NULL) return NULL;
    if(strcmp(r->name,name) == 0) return r;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* q = find(p,name);
        if(q != NULL) return q;
        p = p->rightSibling;
    }
}

Node* addLast(Node* p, char*name){
    if(p == NULL) return makeNode(name);
    p->rightSibling = addLast(p->rightSibling, name);
    return p;
}
void addChild(char*name, char* child){
    Node* r = find(root,name);
    if(r == NULL) return;
    r->leftMostChild = addLast(r->leftMostChild,child);
}

bool check_la(Node*r)
{
    Node*p=r->leftMostChild;
    if(p==NULL) return true;
    return false;
}
void printTree(Node* r){
    if(r == NULL) return;
    if(check_la(r)==false){
        printf("%s: ",r->name);
        Node* p = r->leftMostChild;
        while(p != NULL){
            printf("%s ",p->name);
            p = p->rightSibling;
        }
        printf("\n");
        p = r->leftMostChild;
        while(p != NULL){
            printTree(p);
            p = p->rightSibling;
        }
    }
}
void printTreeF(Node* r, FILE* f){
    if(r == NULL) return;
    if(check_la(r)==false){
        fprintf(f,"%s ",r->name);
        Node* p = r->leftMostChild;
        while(p != NULL){
            fprintf(f,"%s ",p->name);
            p = p->rightSibling;
        }
        fprintf(f," $\n");
        p = r->leftMostChild;
        while(p != NULL){
            printTreeF(p,f);
            p = p->rightSibling;
        }
    }
}
void processFind(){
    printf("Find a node in tree: ");
    char name[256]; scanf("%s",name);
    Node* p = find(root,name);
    if(p == NULL) printf("Not Found %s\n",name);
    else printf("Found %s\n",name);
}
void processFindChildren(){
    printf("Find children node of: ");
    char name[256]; scanf("%s",name);
    Node* p = find(root,name);
    if(p == NULL) printf("Not Found %s\n",name);
    else{
        printf("Found %s with children: ",name);
        Node* q = p->leftMostChild;
        while(q != NULL){
            printf("%s ",q->name); q = q->rightSibling;
        }
    }
    printf("\n");
}

int height(Node* p){
    if(p == NULL) return 0;
    int maxH = 0;
    Node* q = p->leftMostChild;
    while(q != NULL){
        int h = height(q);
        maxH = maxH < h ? h : maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}

void processHeight(){
    char name[256];
    printf("Choose a node: ");
    scanf("%s",name);
    Node* p = find(root,name);
    if(p == NULL) printf("Not Found %s\n",name);
    else{
        printf("Found %s having height = %d\n",name,height(p));
    }
}
int count(Node* r){
    if(r == NULL) return 0;
    int cnt = 1;
    Node* q = r->leftMostChild;
    while(q != NULL){
        cnt += count(q);
        q = q->rightSibling;
    }
    return cnt;
}
void processCount(){
    printf("Number of members is %d\n",count(root));
}
void processStore(){
    printf("filename u want to store: ");
    char filename[256];
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    printTreeF(root,f);
    fprintf(f,"$$");
    fclose(f);
}
void freeTree(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* sp = p->rightSibling;
        freeTree(p);
        p = sp;
    }
    printf("free node %s\n",r->name); free(r);
    r = NULL;
}

void loadTree(char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    root = NULL;
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "$$") == 0) break;
        char* token = strtok(line, " ");
        char name[256];
        strcpy(name, token);
        if (root == NULL) {
            root = makeNode(name);
        }
        while (token != NULL) {
            token = strtok(NULL, " ");
            if (token == NULL || strcmp(token, "$") == 0) break;
            addChild(name, token);
        }
    }
    fclose(f);
}
//dem so nut la trong cay
int cnt_la(Node*r)
{
    if(r==NULL) return 0;
    int s=0;
    Node*p=r->leftMostChild;
    if(p==NULL) s=1;
    while(p!=NULL){
        s+=cnt_la(p);
        p=p->rightSibling;
    }
    return s;
}
//them nut con trai nhat cua 1 nut
void push_left_most(char*name,char*child)
{
    Node*tmp=find(root,name);
    if(tmp==NULL) return;
    else{
        Node*newNode=makeNode(child);
        newNode->rightSibling=tmp->leftMostChild;
        tmp->leftMostChild=newNode;
    }
}
//dem so nut con cua 1 nut cha
int cnt_con(char*name)
{
    Node*tmp=find(root,name);
    if(tmp==NULL) return 0;
    Node*tmp1=tmp->leftMostChild;int cnt=0;
    while(tmp1!=NULL){
        cnt++;
        tmp1=tmp1->rightSibling;
    }
    return cnt;
}
//them nut con vao vi tri k cac danh sach con cua 1 nut cha
void push_at(char*name,char*child,int k)
{
    if(k==0){
        push_left_most(name,child);return;
    }
    Node*tmp=find(root,name);
    if(tmp==NULL) return;
    if(k>cnt_con(tmp)-1) return;
    if(k==cnt_con(tmp)){
        addChild(name,child);return;
    }
    int i=0;
    Node*p=tmp->leftMostChild;Node*prev=NULL;
    while(p!=NULL){
        prev=p;
        p=p->rightSibling;
        i++;
        if(i==k){
            Node*newNode=makeNode(child);
            prev->rightSibling=newNode;newNode->rightSibling=p;
            tmp->rightSibling=newNode;return;
        }
    }
}
//tim cha cua node r1
Node* parent(Node* p, Node* r) {
    if(r == NULL)
        return NULL;

    Node* tmp = r->leftMostChild;
    while(tmp != NULL) {
        if(p == tmp)
            return r;
        Node* tmp1 = parent(p, tmp);
        if(tmp1 != NULL)
            return tmp1;
        tmp = tmp->rightSibling;
    }

    return NULL;
}
void main(){
    while(1){
        char cmd[256];
        printf("Enter command: "); scanf("%s",cmd);
        if(strcmp(cmd,"Quit") == 0) break;
        else if(strcmp(cmd,"Load")==0){
            printf("Filename: ");
            char filename[256];
            scanf("%s",filename);
            loadTree(filename);
        }
        else if(strcmp(cmd,"Print")==0) printTree(root);
        else if(strcmp(cmd,"Find")==0) processFind();
        else if(strcmp(cmd,"FindChildren")==0) processFindChildren();
        else if(strcmp(cmd,"Height")==0) processHeight();
        else if(strcmp(cmd,"Count")==0) processCount();
        else if (strcmp(cmd, "AddChild") == 0) {
            char name[256], child[256];
            printf("Node u want to add: ");
            scanf("%s", name);
            printf("Name of Child node: ");
            scanf("%s",child);
            addChild(name, child);
        }
        else if(strcmp(cmd,"Node_la")==0){
            printf("so nut la cua cay: %d\n",cnt_la(root));
        }
        else if(strcmp(cmd,"push_left_most")==0){
            char name[256], child[256];
            printf("Node u want to add: ");
            scanf("%s", name);
            printf("Name of Child node: ");
            scanf("%s",child);
            push_left_most(name,child);
        }else if(strcmp(cmd,"Node_con")==0)
        {
            char name[256];scanf("%s",name);
            printf("So nut con cua nut %s: %d\n",name,cnt_con(name));
        }
        else if(strcmp(cmd,"Add_at"))
        {
            char name[256],child[256];int k;scanf("%s%s%d",name,child,&k);
            push_at(name,child,k);
        }
        else if(strcmp(cmd,"Find_parent"))
        {
            char*name[256];scanf("%s",name);
            Node*tmp=find(root,name);
            if(tmp==NULL){
                printf("Khong tim thay!");
            }else{
                printf("Nut cha cua %s la: %s",name,parent(tmp,root));
            }
        }
        else if(strcmp(cmd,"Store")==0) processStore();
    }
    freeTree(root);
    return 0;
}

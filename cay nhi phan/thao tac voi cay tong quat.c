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
        else if(strcmp(cmd,"Store")==0) processStore();
    }
    freeTree(root);
    return 0;
}

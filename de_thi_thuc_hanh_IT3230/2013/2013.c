#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

#define Max_Len 10

typedef struct Doi_bong {
    char name_doi_bong[Max_Len];
    int diem;
} Doi_bong;

typedef struct TreeNode {
    Doi_bong data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Node {
    Doi_bong data;
    struct Node* next;
} Node;

TreeNode* root = NULL;
Node* head = NULL;

TreeNode* makeNode(char* namedb, int diem) {
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newnode->data.name_doi_bong, namedb);
    newnode->data.diem = diem;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node* newNode(char* namedb, int diem) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->data.name_doi_bong, namedb);
    newnode->data.diem = diem;
    newnode->next = NULL;
    return newnode;
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s %d\n", root->data.name_doi_bong, root->data.diem);
        inorder(root->right);
    }
}

void pushback(Node** head, Node* tmp) {
    if (*head == NULL) {
        *head = tmp;
        return;
    }
    Node* tmp1 = *head;
    while (tmp1->next != NULL) {
        tmp1 = tmp1->next;
    }
    tmp1->next = tmp;
}

Node* find_Node(Node* head, char* name_db) {
    Node* tmp = head;
    while (tmp != NULL) {
        if (strcmp(tmp->data.name_doi_bong, name_db) == 0) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

// Return value:
// 1 -> Team A wins
// 2 -> Team B wins
// 0 -> Draw
int check_ti_so(int a, int b) {
    if (a > b) return 1;
    else if (a < b) return 2;
    else if (a == b) return 0;
}

int cmp(TreeNode* a, Node* b) {
    return strcmp(a->data.name_doi_bong, b->data.name_doi_bong);
}

TreeNode* insert(TreeNode* root, Node* tmp) {
    if (root == NULL) {
        TreeNode* tmp1 = makeNode(tmp->data.name_doi_bong, tmp->data.diem);
        return tmp1;
    }
    int compare = cmp(tmp, root);
    if (compare < 0) {
        root->left = insert(root->left, tmp);
    }
    else if (compare > 0) {
        root->right = insert(root->right, tmp);
    }
    return root;
}

void xulyfile(char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong tim thay file!\n");
        return;
    }
    while (!feof(f)) {
        char namedb1[Max_Len], namedb2[Max_Len];
        int diem1, diem2;
        fscanf(f, "%s\t%s\t%d\t%d\n", namedb1, namedb2, &diem1, &diem2);
        Node* db1 = find_Node(head, namedb1);
        Node* db2 = find_Node(head, namedb2);
        if (db1 == NULL) {
            Node* tmp = newNode(namedb1, 0);
            pushback(&head, tmp);
        }
        if (db2 == NULL) {
            Node* tmp = newNode(namedb2, 0);
            pushback(&head, tmp);
        }
    }
    fseek(f, 0, SEEK_SET);
    while (!feof(f)) {
        char namedb1[Max_Len], namedb2[Max_Len];
        int diem1, diem2;
        fscanf(f, "%s\t%s\t%d\t%d\n", namedb1, namedb2, &diem1, &diem2);
        Node* db1 = find_Node(head,namedb1);
        Node* db2 = find_Node(head,namedb2);
        if (check_ti_so(diem1, diem2) == 1) {
            db1->data.diem += 3;
        }
        else if (check_ti_so(diem1, diem2) == 2) {
            db2->data.diem += 3;
        }
        else if (check_ti_so(diem1, diem2) == 0) {
            db1->data.diem += 1;
            db2->data.diem += 1;
        }
    }
    Node* tmp = head;
    int i = 1;
    while (tmp != NULL) {
        root = insert(root, tmp);
        printf("Nut moi thu %d co dia chi %p\n", i, (void*)tmp);
        //printf("%s %d\n",tmp->data.name_doi_bong,tmp->data.diem);
        tmp = tmp->next;
        i++;
    }
    fclose(f);
}

void Inorder(TreeNode* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%s %d\n", root->data.name_doi_bong, root->data.diem);
        Inorder(root->right);
    }
}

TreeNode*find(TreeNode*root,char*namedb)
{
    if(root==NULL){
        return NULL;
    }
    if(strcmp(root->data.name_doi_bong,namedb)==0) return root;
    TreeNode*tmp1=find(root->left,namedb);
    if(tmp1!=NULL) return tmp1;
    return find(root->right,namedb);
}
void xoadoibong(TreeNode* root, TreeNode* tmp) {
    if (tmp->left == NULL && tmp->right == NULL) {
        printf("Doi bong bi xuong hang la %s\n", tmp->data.name_doi_bong);
        free(tmp);
        return;
    }
    if (tmp->left == NULL) {
        TreeNode* child = tmp->right;
        *tmp = *child;
        free(child);
        printf("Doi bong bi xuong hang la %s\n", tmp->data.name_doi_bong);
        return;
    }
    if (tmp->right == NULL) {
        TreeNode* child = tmp->left;
        *tmp = *child;
        free(child);
        printf("Doi bong bi xuong hang la %s\n", tmp->data.name_doi_bong);
        return;
    }
    TreeNode* successor = tmp->right;
    while (successor->left != NULL) {
        successor = successor->left;
    }
    TreeNode* parent = find(root, successor->data.name_doi_bong);
    tmp->data = successor->data;
    if (parent != NULL) {
        if (parent->left == successor) {
            parent->left = successor->right;
        }
        else {
            parent->right = successor->right;
        }
    }
    else {
        tmp->right = successor->right;
    }
    free(successor);
    printf("Doi bong bi xuong hang la %s\n", tmp->data.name_doi_bong);
}
void destroyTree(TreeNode* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}
void destroy_dslk(Node*head)
{
    Node*tmp=head;
    while(tmp!=NULL){
        Node*tp=tmp;
        tmp=tmp->next;
        free(tp);
    }
}
void xuatfile(FILE*f,TreeNode*root)
{
    if(root!=NULL){
        fprintf(f,"%s %d\n",root->data.name_doi_bong,root->data.diem);
        xuatfile(f,root->left);
        xuatfile(f,root->right);
    }
}
int main() {
    while (1) {
        printf("-----------------\n");
        printf("1. Tao cay\n");
        printf("2. Ket qua\n");
        printf("3. Tim kiem\n");
        printf("4. Xuong hang\n");
        printf("5. Xuat file\n");
        printf("-----------------\n");
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            xulyfile("Bongda.txt");
        }
        else if (cmd == 2) {
            Inorder(root);
        }else if(cmd==3){
            char ma_db[Max_Len];
            printf("Nhap ma doi bong can tim kiem: ");
            scanf("%s",ma_db);
            TreeNode*tmp=find(root,ma_db);
            if(tmp==NULL){
                printf("khong tim thay ma doi bong!\n");
            }else{
                printf("diem cua doi bong nay: %d\n",tmp->data.diem);
            }
        }else if(cmd==4){
            int x;
            printf("diem so can phai lon hon: ");
            scanf("%d",&x);
            Node*tmp=head;
            while(tmp!=NULL){
                if(tmp->data.diem<x){
                    TreeNode*tp=find(root,tmp->data.name_doi_bong);
                    xoadoibong(root,tp);
                }
                tmp=tmp->next;
            }
            printf("Cac doi khong xuong hang: \n");
            Inorder(root);
        }else if(cmd==5){
            FILE*f=fopen("Ketqua.txt","w");
            xuatfile(f,root);
            fclose(f);
        }else break;
    }
}

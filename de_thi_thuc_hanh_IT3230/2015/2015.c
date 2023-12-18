#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_Len 30

typedef struct Ds {
    int ma_so;
    char do_choi[Max_Len];
} Ds;

typedef struct TreeNode {
    Ds data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Node{
    Ds data;
    int dd;
    struct Node*next;
}Node;

Ds mangB[Max_Len];
TreeNode* root = NULL;
int n = 0;
Node*head=NULL;
TreeNode* makeNode(int ma_so, char*do_choi) {
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    newnode->data.ma_so = ma_so;
    strcpy(newnode->data.do_choi, do_choi);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
Node*newNode(int ma_so, char*do_choi)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data.ma_so = ma_so;
    strcpy(newnode->data.do_choi, do_choi);
    newnode->dd=0;
    newnode->next = NULL;
    return newnode;
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
TreeNode*find(TreeNode*root,int ma1)
{
    if(root==NULL) return NULL;
    if(root->data.ma_so==ma1) return root;
    TreeNode*tp=find(root->left,ma1);
    if(tp!=NULL) return tp;
    return find(root->right,ma1);
}
int cmp(int a, int b) {
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

TreeNode* insert(TreeNode* root, TreeNode* tmp) {
    if (root == NULL) {
        return tmp;
    }
    int compare = cmp(tmp->data.ma_so, root->data.ma_so);
    if (compare < 0) {
        root->left = insert(root->left, tmp);
    }
    else if (compare > 0) {
        root->right = insert(root->right, tmp);
    }
    return root;
}
void xu_ly_file_A(char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong ton tai file!\n");
        return;
    }
    char tmp[Max_Len * 2];
    while (fgets(tmp, sizeof(tmp), f)) {
        tmp[strcspn(tmp, "\n")] = '\0';
        char dochoi[Max_Len];
        int ma1;
        if (strlen(tmp) < 5) {
            printf("Ma %d con thieu do choi!\n",atoi(tmp));
            printf("Nhap do choi con thieu: ");
            scanf("%s", dochoi);
            ma1 = atoi(tmp);
            TreeNode*tp1=makeNode(ma1,dochoi);
            root=insert(root,tp1);
        }
        else {
            char*token=strtok(tmp,"\t");
            int i=0;
            while(token!=NULL){
                if(i==0){
                    ma1=atoi(token);
                }else if(i==1){
                    strcpy(dochoi,token);
                }
                token=strtok(NULL,"\t");
                i++;
            }
            TreeNode*tp1=makeNode(ma1,dochoi);
            root=insert(root,tp1);
        }
    }
    fclose(f);
}

void xu_ly_file_B(char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong ton tai file!\n");
        return;
    }
    char tmp[Max_Len * 2];
    while (fgets(tmp, sizeof(tmp), f)) {
        tmp[strcspn(tmp, "\n")] = '\0';
        char dochoi[Max_Len];
        int ma1;
        if (strlen(tmp) < 5) {
            printf("Ma %d con thieu do choi!\n",atoi(tmp));
            printf("Nhap do choi con thieu: ");
            scanf("%s", dochoi);
            mangB[n].ma_so = atoi(tmp);
            strcpy(mangB[n].do_choi, dochoi);
        }
        else {
            char*token=strtok(tmp,"\t");
            int i=0;
            while(token!=NULL){
                if(i==0){
                    ma1=atoi(token);
                }else if(i==1){
                    strcpy(dochoi,token);
                }
                token=strtok(NULL,"\t");
                i++;
            }
            mangB[n].ma_so = ma1;
            strcpy(mangB[n].do_choi, dochoi);
        }
        n++;
    }
    fclose(f);
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("ma= %d, do choi= %s\n", root->data.ma_so, root->data.do_choi);
        inorder(root->right);
    }
}
void print(TreeNode* root) {
    if (root != NULL) {
        inorder(root->right);
        printf("ma= %d, do choi= %s\n", root->data.ma_so, root->data.do_choi);
        inorder(root->left);
    }
}
void xoa_ma(TreeNode* root, TreeNode* tmp) {
    if (tmp->left == NULL && tmp->right == NULL) {
        //printf("Em nho bi trung la: %d\n", tmp->data.ma_so);
        free(tmp);
        return;
    }
    if (tmp->left == NULL) {
        TreeNode* child = tmp->right;
        *tmp = *child;
        free(child);
        //printf("Em nho bi trung la: %d\n", tmp->data.ma_so);
        return;
    }
    if (tmp->right == NULL) {
        TreeNode* child = tmp->left;
        *tmp = *child;
        free(child);
        //printf("Em nho bi trung la: %d\n", tmp->data.ma_so);
        return;
    }
    TreeNode* successor = tmp->right;
    while (successor->left != NULL) {
        successor = successor->left;
    }
    TreeNode* parent = find(root, successor->data.ma_so);
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
    //printf("Em nho bi trung la: %d\n", tmp->data.ma_so);
}
void chuyen_doi(TreeNode*root)
{
    if(root!=NULL){
        Node*tmp=newNode(root->data.ma_so,root->data.do_choi);
        pushback(&head,tmp);
        chuyen_doi(root->left);
        chuyen_doi(root->right);
    }
}
void thong_ke(Node* head) {
    for (Node* tmp = head; tmp != NULL; tmp = tmp->next) {
        if (tmp->dd != -1) {
            int cnt = 1;
            tmp->dd = -1;

            for (Node* tmp1 = tmp->next; tmp1 != NULL; tmp1 = tmp1->next) {
                if (tmp1->dd != -1 && strcmp(tmp1->data.do_choi, tmp->data.do_choi) == 0) {
                    cnt++;
                    tmp1->dd = -1;
                }
            }

            printf("%s lap lai %d lan\n", tmp->data.do_choi, cnt);
        }
    }
}

int main() {
    while (1) {
        printf("----------------\n");
        printf("1.Doc file A\n");
        printf("2.Doc file B\n");
        printf("3.Tim kiem\n");
        printf("4.Tong hop\n");
        printf("5.Thong ke\n");
        printf("6.Thoat\n");
        printf("----------------\n");
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            xu_ly_file_A("A.txt.txt");
            inorder(root);
        }
        else if (cmd == 2) {
            xu_ly_file_B("B.txt.txt");
            for (int i = 0; i < n; i++) {
                printf("ma= %d, do choi= %s\n", mangB[i].ma_so, mangB[i].do_choi);
            }
        }else if(cmd==3){
            for(int i=0;i<n;i++){
                TreeNode*tmp=find(root,mangB[i].ma_so);
                if(tmp!=NULL){
                    xoa_ma(root,tmp);
                    printf("Em nho bi xoa la: ");
                    printf("%d %s\n",mangB[i].ma_so,tmp->data.do_choi);
                }
            }
            n--;
            inorder(root);
        }else if(cmd==4){
            for(int i=0;i<n;i++){
                TreeNode*tp=makeNode(mangB[i].ma_so,mangB[i].do_choi);
                root=insert(root,tp);
            }
            print(root);
        }else if(cmd==5){
            chuyen_doi(root);
            thong_ke(head);
        }
        else if (cmd == 6)
            break;

    }
    return 0;
}

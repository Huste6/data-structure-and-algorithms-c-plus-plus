#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define Max_Len 30

typedef struct Thongtin {
    char ma_yeu_cau[Max_Len];
    int so_nguoi;
    int so_phong;
    char ma_khach_san[Max_Len];
    char thoi_gian[Max_Len];
    int so_tre_em;
} Thongtin;

typedef struct TreeNode {
    Thongtin data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Node {
    Thongtin data;
    struct Node* next;
} Node;

TreeNode* root = NULL;
Node* head = NULL;
int khl = 0;

Node* makeNode(char ma_yeu_cau[], int so_nguoi, int so_phong, char ma_khach_san[], char thoi_gian[], int so_tre_em) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->data.ma_yeu_cau, ma_yeu_cau);
    newnode->data.so_nguoi = so_nguoi;
    newnode->data.so_phong = so_phong;
    strcpy(newnode->data.ma_khach_san, ma_khach_san);
    strcpy(newnode->data.thoi_gian, thoi_gian);
    newnode->data.so_tre_em = so_tre_em;
    newnode->next = NULL;
    return newnode;
}

TreeNode* makeTree(char ma_yeu_cau[], int so_nguoi, int so_phong, char ma_khach_san[], char thoi_gian[], int so_tre_em) {
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newnode->data.ma_yeu_cau, ma_yeu_cau);
    newnode->data.so_nguoi = so_nguoi;
    newnode->data.so_phong = so_phong;
    strcpy(newnode->data.ma_khach_san, ma_khach_san);
    strcpy(newnode->data.thoi_gian, thoi_gian);
    newnode->data.so_tre_em = so_tre_em;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void pushback(Node** head, Node* tmp) {
    if (*head == NULL) {
        *head = tmp;
        return;
    }
    Node* tp = *head;
    while (tp->next != NULL) {
        tp = tp->next;
    }
    tp->next = tmp;
}

bool check_tre(int so_nguoi, int so_tre) {
    if (so_nguoi == so_tre || so_nguoi < so_tre) return false;
    return true;
}

void xu_ly_file(char* filename) {
    FILE* f = fopen(filename, "r");
    int n;
    fscanf(f, "%d\n", &n);
    char ma_yeu_cau[Max_Len];
    int so_nguoi;
    int so_phong;
    char ma_khach_san[Max_Len];
    char thoi_gian[Max_Len];
    int so_tre_em;
    for (int i = 0; i < n; i++) {
        fscanf(f, "%s %d %d %s %s %d\n", ma_yeu_cau, &so_nguoi, &so_phong, ma_khach_san, thoi_gian, &so_tre_em);
        Node* tmp = makeNode(ma_yeu_cau, so_nguoi, so_phong, ma_khach_san, thoi_gian, so_tre_em);
        pushback(&head, tmp);
        if (check_tre(so_nguoi, so_tre_em) == false) khl++;
    }
    fclose(f);
}

int cmp(const char* a, const char* b) {
    return strcmp(a, b);
}

TreeNode* insert(TreeNode* root, TreeNode* tp) {
    if (root == NULL) {
        return tp;
    }
    int compare = cmp(root->data.ma_yeu_cau, tp->data.ma_yeu_cau);
    if (compare > 0) {
        root->left = insert(root->left, tp);
    }
    else if (compare < 0) {
        root->right = insert(root->right, tp);
    }
    return root;
}

void luu_vao_cay(TreeNode** root, Node** head) {
    Node* tmp = *head;
    while (tmp != NULL) {
        TreeNode* tp = makeTree(tmp->data.ma_yeu_cau, tmp->data.so_nguoi, tmp->data.so_phong, tmp->data.ma_khach_san, tmp->data.thoi_gian, tmp->data.so_tre_em);
        *root = insert(*root, tp);
        tmp = tmp->next;
    }
}

TreeNode* find(TreeNode* root, char*ma_yeu_cau) {
    if (root == NULL) {
        return NULL;
    }
    int compare = cmp(root->data.ma_yeu_cau, ma_yeu_cau);
    if (compare == 0) return root;
    else if (compare > 0) return find(root->left, ma_yeu_cau);
    else return find(root->right, ma_yeu_cau);
}

void printNode(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        printf("%s %d %d %s %s %d\n", tmp->data.ma_yeu_cau, tmp->data.so_nguoi, tmp->data.so_phong, tmp->data.ma_khach_san, tmp->data.thoi_gian, tmp->data.so_tre_em);
        tmp = tmp->next;
    }
}

void XoaNode(TreeNode** root, TreeNode* tmp) {
    if (*root == NULL)
        return;

    if (strcmp(tmp->data.ma_yeu_cau, (*root)->data.ma_yeu_cau) < 0) {
        XoaNode(&(*root)->left, tmp);
    }
    else if (strcmp(tmp->data.ma_yeu_cau, (*root)->data.ma_yeu_cau) > 0) {
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
void Xoa_node_tren_cay(TreeNode** root, TreeNode* tmp) {
    if (tmp->left == NULL && tmp->right == NULL) {
        free(tmp);
        return;
    }
    if (tmp->left == NULL) {
        TreeNode* child = tmp->right;
        *tmp = *child;
        free(child);
        return;
    }
    if (tmp->right == NULL) {
        TreeNode* child = tmp->left;
        *tmp = *child;
        free(child);
        return;
    }
    TreeNode* successor = tmp->right;
    while (successor->left != NULL) {
        successor = successor->left;
    }
    TreeNode* parent = find(&(*root), successor->data.ma_yeu_cau);
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
}
void xuatfile(FILE* f, TreeNode* root) {
    if (root != NULL) {
        fprintf(f, "%s %d %d %s %s %d\n", root->data.ma_yeu_cau, root->data.so_nguoi, root->data.so_phong, root->data.ma_khach_san, root->data.thoi_gian, root->data.so_tre_em);
        xuatfile(f, root->left);
        xuatfile(f, root->right);
    }
}

void destroyTree(TreeNode* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s %d %d %s %s %d\n", root->data.ma_yeu_cau, root->data.so_nguoi, root->data.so_phong, root->data.ma_khach_san, root->data.thoi_gian, root->data.so_tre_em);
        inorder(root->right);
    }
}

int main() {
    while (1) {
        printf("----------------------------------\n");
        printf("1. Doc file\n");
        printf("2. So luong yeu cau khong hop le\n");
        printf("3. Dua du lieu vao cay\n");
        printf("4. Ghi vao file\n");
        printf("5. In ra man hinh\n");
        printf("----------------------------------\n");

        int cmd;
        scanf("%d", &cmd);

        if (cmd == 1) {
            xu_ly_file("booking_orders.txt");
        } else if (cmd == 2) {
            printf("So luong yeu cau khong hop le: %d\n", khl);
        } else if (cmd == 3) {
             luu_vao_cay(&root, &head);
             while(1){
                printf("------------------\n");
                printf("a.Tim kiem thong tin\n");
                printf("b.cap nhat yeu cau\n");
                printf("c.Huy yeu cau\n");
                printf("------------------\n");
                char cmd1[2];
                scanf("%s",cmd1);
                if(strcmp(cmd1,"a")==0){
                    printf("Nhap yeu cau can tim kiem: ");
                    char myc[Max_Len];scanf("%s",myc);

                    TreeNode*tmp=find(root,myc);
                    if(tmp==NULL){
                        printf("Not Found!\n");
                    }else{
                        printf("Du lieu cua ma yeu cau: %s %d %d %s %s %d\n",tmp->data.ma_yeu_cau,tmp->data.so_nguoi,tmp->data.so_phong,tmp->data.ma_khach_san,tmp->data.thoi_gian,tmp->data.so_tre_em);
                    }
                }else if(strcmp(cmd1,"b")==0){
                    char ntn[Max_Len];int sln,so_tre;
                    printf("Nhap yeu cau can thay doi: ");
                    char myc[Max_Len];scanf("%s",myc);
                    TreeNode*tmp=find(root,myc);
                    if(tmp==NULL){
                        printf("Not Found!\n");
                    }else{
                        printf("Ngay-thang-nam: ");scanf("%s",ntn);
                        printf("So luong nguoi: ");scanf("%d",&sln);
                        printf("so tre em: ");scanf("%d",&so_tre);
                        if(check_tre(sln,so_tre)==false) printf("Invalid!\n");
                        else{
                        strcpy(tmp->data.thoi_gian,ntn);
                        tmp->data.so_nguoi=sln;
                        tmp->data.so_tre_em=so_tre;
                        printf("Update!\n");}
                    }
                }else if(strcmp(cmd1,"c")==0){
                    printf("Nhap yeu cau can huy: ");
                    char myc[Max_Len];scanf("%s",myc);
                    TreeNode*tmp=find(root,myc);
                    if(tmp==NULL){
                        printf("Not Found!\n");
                    }else{
                        XoaNode(&root,tmp);
                        //Xoa_node_tren_cay(&root,tmp);
                        printf("Delete!\n");
                    }
                }else break;
            }
        } else if (cmd == 4) {
            FILE* f = fopen("booking_output.txt", "w");
            xuatfile(f, root);
            fclose(f);
        } else if (cmd == 5) {
            //luu_vao_cay(&root, &head);
            inorder(root);
        }
    }
    destroyTree(root);
    return 0;
}


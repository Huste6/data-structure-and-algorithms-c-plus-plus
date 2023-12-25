#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define Max_Len 20

typedef struct SV {
    char user[Max_Len];
    char pass[Max_Len];
    double diem;
} SV;

typedef struct TreeNode {
    SV data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* root = NULL;

// Function to create a new tree node
TreeNode* makeNode(char* name, char* pass, double diem) {
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newnode->data.user, name);
    strcpy(newnode->data.pass, pass);
    newnode->data.diem = diem;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to find a node with a given username
TreeNode* find(TreeNode* root, char* name) {
    if (root == NULL) return NULL;
    if (strcmp(root->data.user, name) == 0) return root;
    TreeNode* tmp1 = find(root->left, name);
    if (tmp1 != NULL) return tmp1;
    return find(root->right, name);
}

// Function to find a node with a given password
TreeNode* find1(TreeNode* root, char* pass) {
    if (root == NULL) return NULL;
    if (strcmp(root->data.pass, pass) == 0) return root;
    TreeNode* tmp1 = find1(root->left, pass);
    if (tmp1 != NULL) return tmp1;
    return find1(root->right, pass);
}

// Function to compare two tree nodes based on usernames
int cmp(TreeNode* a, TreeNode* b) {
    if (strcmp(a->data.user, b->data.user) > 0) return 1;
    if (strcmp(a->data.user, b->data.user) < 0) return -1;
    return 0;
}

// Function to insert a new node into the tree
TreeNode* insert(TreeNode* root, TreeNode* newnode) {
    if (root == NULL) {
        return newnode;
    }
    int compare = cmp(newnode, root);
    if (compare < 0) {
        root->left = insert(root->left, newnode);
    } else if (compare > 0) {
        root->right = insert(root->right, newnode);
    }
    return root;
}

// Function to check if a string contains only non-whitespace characters
bool check_dang_nhap(char* name) {
    while (*name) {
        if (isspace((unsigned char)(*name))) {
            return false;
        }
        name++;
    }
    return true;
}

// Function to check if a username exists in the tree
bool check_name(TreeNode* root, char* name) {
    TreeNode* tmp = find(root, name);
    return tmp != NULL;
}

// Function to check if a password exists in the tree
bool check_pass(TreeNode* root, char* pass) {
    TreeNode* tmp = find1(root, pass);
    return tmp != NULL;
}

// Function to process data from a file and build the tree
void xu_ly_file(char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong tim thay file!\n");
        return;
    }

    while (!feof(f)) {
        char name[Max_Len], pass[Max_Len];
        double diem;
        fscanf(f, "%s %s %lf\n", name, pass, &diem);
        //TreeNode* parent = NULL;
        if (root == NULL) {
            root = makeNode(name, pass, diem);
            //parent = root;
        } else {
            TreeNode* newnode = makeNode(name, pass, diem);
            root = insert(root, newnode);
        }
    }
    fclose(f);
}

// Function to store tree data into a file
void store(FILE* f, TreeNode* root) {
    if (root != NULL) {
        fprintf(f, "%s %s %lf\n", root->data.user, root->data.pass, root->data.diem);
        store(f, root->left);
        store(f, root->right);
    }
}

// Function to print the tree data
void print(TreeNode* root) {
    if (root != NULL) {
            print(root->left);
            if (strcmp(root->data.user, "Admin") != 0) {
                printf("%s %s %lf\n", root->data.user, root->data.pass, root->data.diem);
            }
            print(root->right);

    }
}

// Function to delete a student from the tree
void Xoasinhvien(TreeNode* root) {
    char namesv[Max_Len];
    printf("Nhap ten sinh vien can xoa: ");
    scanf("%s", namesv);

    TreeNode* tmp = find(root, namesv);
    if (tmp == NULL) {
        printf("Khong tim thay sinh vien!\n");
        return;
    }

    // Case 1: Node has no children
    if (tmp->left == NULL && tmp->right == NULL) {
        free(tmp);
        printf("Xoa sinh vien thanh cong!\n");
        return;
    }

    // Case 2: Node has one child
    if (tmp->left == NULL) {
        TreeNode* child = tmp->right;
        *tmp = *child;
        free(child);
        printf("Xoa sinh vien thanh cong!\n");
        return;
    }
    if (tmp->right == NULL) {
        TreeNode* child = tmp->left;
        *tmp = *child;
        free(child);
        printf("Xoa sinh vien thanh cong!\n");
        return;
    }

    TreeNode* successor = tmp->right;
    while (successor->left != NULL) {
        successor = successor->left;
    }
    TreeNode* parent = find(root, successor->data.user);
    tmp->data = successor->data;
    if (parent != NULL) {
        if (parent->left == successor) {
            parent->left = successor->right;
        } else {
            parent->right = successor->right;
        }
    } else {
        tmp->right = successor->right;
    }
    free(successor);
}

TreeNode* findParent(TreeNode* root, TreeNode* node) {
    if (root == NULL || root == node) return NULL;
    if ((root->left == node) || (root->right == node)) return root;
    if (strcmp(node->data.user, root->data.user) < 0) {
        return findParent(root->left, node);
    } else {
        return findParent(root->right, node);
    }
}

void destroyTree(TreeNode* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int main() {
    xu_ly_file("sinhvien.txt.txt");
    while (1) {
        printf("---------------------\n");
        printf("1.Dang nhap\n");
        printf("2.Thoat\n");
        printf("---------------------\n");
        int cmd;
        scanf("%d", &cmd);

        if(cmd == 1) {
            int i = 0;
            char user[Max_Len];
            char pass[Max_Len];
            do {
                i++;
                if (i > 1) {
                    printf("Vui long nhap lai!\n");
                } else if (i >= 5) {
                    break;
                }
                printf("UserName: ");
                scanf("%s", user);
            } while (check_dang_nhap(user) == false || check_name(root, user) == false);
            if (i >= 5) break;
            i = 0;
            do {
                i++;
                if (i > 1) {
                    printf("Vui long nhap lai!\n");
                } else if (i >= 5) {
                    break;
                }
                printf("PassWord: ");
                scanf("%s", pass);
            } while (check_dang_nhap(pass) == false || check_pass(root, pass) == false);
            if (i >= 5) break;
            else printf("Dang nhap thanh cong =>> \n");
            TreeNode* tmp = find(root, user);
            if (strcmp(user, "Admin") != 0) {
                while (1) {
                    printf("--------------------------\n");
                    printf("1.Xem diem\n");
                    printf("2.Thay doi mat khau\n");
                    printf("3.Ghi lai thong tin tren file\n");
                    printf("--------------------------\n");
                    int cmd1;
                    scanf("%d", &cmd1);
                    if (cmd1 == 1) {
                        printf("Diem cua ban la: %lf\n", tmp->data.diem);
                    } else if (cmd1 == 2) {
                        char mk[Max_Len], mk1[Max_Len];
                        printf("Nhap mat khau moi: ");
                        scanf("%s", mk);
                        printf("Nhap lai mat khau moi: ");
                        scanf("%s", mk1);
                        while (strcmp(mk, mk1) != 0) {
                            printf("Vui long nhap mat khau giong voi mat khau moi: ");
                            scanf("%s", mk1);
                        }
                        printf("Nhap thanh cong=>> \n");
                        strcpy(tmp->data.pass, mk);
                    } else if (cmd1 == 3) {
                        FILE* f = fopen("sinhvien.txt", "w");
                        store(f, root);
                        fclose(f);
                        printf("\n");
                        break;
                    }
                }
            } else {
                while (1) {
                    printf("------------------------\n");
                    printf("1.In danh sach sinh vien\n");
                    printf("2.Xoa sinh vien\n");
                    printf("3.Them 1 sinh vien\n");
                    printf("4.Luu vao file va Thoat\n");
                    printf("------------------------\n");
                    int cmd2;
                    scanf("%d", &cmd2);
                    if (cmd2 == 1) {
                        printf("Danh sach sinh vien:\n");
                        print(root);
                    } else if (cmd2 == 2) {
                        Xoasinhvien(root);
                    } else if (cmd2 == 4) {
                        FILE* f = fopen("sinhvien.txt", "w");
                        store(f, root);
                        fclose(f);
                        printf("\n");
                        break;
                    }else if(cmd2==3){
                        char name[Max_Len],pass[Max_Len];double diem;
                        printf("Nhap username sinh vien can them: ");scanf("%s",name);
                        printf("Nhap password sinh vien can them: ");scanf("%s",pass);
                        printf("Nhap diem sinh vien: ");scanf("%lf",&diem);
                        TreeNode*newnode=makeNode(name,pass,diem);
                        root=insert(root,newnode);
                        printf("Them thanh cong =>> \n");
                    }
                }
            }
        }
        else if (cmd == 2) {
            break;
        } else {
            printf("Lenh khong hop le! Vui long thu lai.\n");
        }
    }
    destroyTree(root);  // Free memory before exiting
    return 0;
}

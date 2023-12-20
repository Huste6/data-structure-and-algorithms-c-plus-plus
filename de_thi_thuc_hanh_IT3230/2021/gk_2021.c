#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_Len 20

typedef struct DSTM
{
    char ngay_thang_nam[Max_Len];
    char seller[Max_Len];
    char buyer[Max_Len];
    char ProductID[Max_Len];
    int number;
    int cost;
}DSTM;

typedef struct TreeNode
{
    DSTM data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* root = NULL;

TreeNode* makeTree(char ngay_thang_nam[], char seller[], char buyer[], char ProductID[], int number, int cost)
{
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newnode->data.ngay_thang_nam, ngay_thang_nam);
    strcpy(newnode->data.seller, seller);
    strcpy(newnode->data.buyer, buyer);
    strcpy(newnode->data.ProductID, ProductID);
    newnode->data.number = number;
    newnode->data.cost = cost;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int cmp(TreeNode* a, TreeNode* b)
{
    if (a->data.cost > b->data.cost) return 1;
    if (a->data.cost < b->data.cost) return -1;
    if (a->data.number > b->data.number) return 1;
    if (a->data.number < b->data.number) return -1;
    if (strcmp(a->data.ProductID, b->data.ProductID) > 0) return 1;
    if (strcmp(a->data.ProductID, b->data.ProductID) < 0) return -1;
    if (strcmp(a->data.ngay_thang_nam, b->data.ngay_thang_nam) > 0) return 1;
    if (strcmp(a->data.ngay_thang_nam, b->data.ngay_thang_nam) < 0) return -1;
    char combinedSellerBuyerA[100];
    strcpy(combinedSellerBuyerA, a->data.seller);
    strcat(combinedSellerBuyerA, "_");
    strcat(combinedSellerBuyerA, a->data.buyer);

    char combinedSellerBuyerB[100];
    strcpy(combinedSellerBuyerB, b->data.seller);
    strcat(combinedSellerBuyerB, "_");
    strcat(combinedSellerBuyerB, b->data.buyer);
    if (strcmp(combinedSellerBuyerA, combinedSellerBuyerB) > 0) return 1;
    if (strcmp(combinedSellerBuyerA, combinedSellerBuyerB) < 0) return -1;
    return 0;
}

TreeNode* insert(TreeNode* root, TreeNode* tmp)
{
    if (root == NULL) {
        return tmp;
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

void xu_ly_file(char* filename)
{
    FILE* f = fopen(filename, "r");
    int i = 0, j = 0;
    int index = 0;
    double max1 = 0;
    while (!feof(f)) {
        char ngay_thang_nam[Max_Len];
        char seller[Max_Len];
        char buyer[Max_Len];
        char ProductID[Max_Len];
        int number;
        int cost;
        fscanf(f, "%s %s %s %s %d %d\n", ngay_thang_nam, seller, buyer, ProductID, &number, &cost);
        if (strcmp(ngay_thang_nam, "$") == 0) break;
        if (cost > 1 && cost < 2000000) i++;
        if (number < 100 && number > 0) j++;
        if (max1 < (cost) / number) {
            max1 = (cost) / number;
            index = i;
        }
        TreeNode* tmp = makeTree(ngay_thang_nam, seller, buyer, ProductID, number, cost);
        root = insert(root, tmp);
    }
    printf("Co %d dong hop le ve yeu cau so tien\n", i);
    printf("Co %d dong hop le ve yeu cau so san pham\n", j);
    printf("Dong %d co so tien trong 1 san pham lon nhat la %lf yen\n", index, max1);
    fclose(f);
}

void inorder(TreeNode* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%s %s %s %s %d %d\n", root->data.ngay_thang_nam, root->data.seller, root->data.buyer, root->data.ProductID, root->data.number, root->data.cost);
        inorder(root->right);
    }
}

int Height(TreeNode* node)
{
    if (node == NULL)
        return 0;
    else {
        int lDepth = Height(node->left);
        int rDepth = Height(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void destroyTree(TreeNode* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int main()
{
    xu_ly_file("testcasegk.txt");
    inorder(root);
    printf("chieu cao cua cay: %d\n", Height(root));
    destroyTree(root);
    return 0;
}

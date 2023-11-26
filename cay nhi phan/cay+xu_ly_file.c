#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *leftmostchild;
    struct TreeNode *rightchild;
} TreeNode;

TreeNode *root;

TreeNode *makeNode(int x)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = x;
    newNode->leftmostchild = NULL;
    newNode->rightchild = NULL;
    return newNode;
}

TreeNode *find(TreeNode *root, int x)
{
    if (root == NULL)
        return NULL;
    if (root->data == x)
        return root;
    TreeNode *tmp = find(root->leftmostchild, x);
    if (tmp != NULL)
        return tmp;
    return find(root->rightchild, x);
}

void insert(TreeNode *parent, int x)
{
    TreeNode *newnode = makeNode(x);
    if (parent->leftmostchild == NULL)
        parent->leftmostchild = newnode;
    else
    {
        TreeNode *tmp = parent->leftmostchild;
        while (tmp->rightchild != NULL)
        {
            tmp = tmp->rightchild;
        }
        tmp->rightchild = newnode;
    }
}

void Load(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Khong the mo file!\n");
        return;
    }
    root = NULL;
    int i = 0;
    char str[100];
    TreeNode *parent = NULL;
    while (fgets(str, sizeof(str), f) != NULL)
    {
        str[strlen(str) - 1] = '\0';
        char *token = strtok(str, " ");
        if (i == 0)
        {
            root = makeNode(atoi(token));
        }
        else
        {
            parent = find(root, atoi(token));
        }
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            if (token != NULL && strcmp(token, ":") != 0 && i > 0)
            {
                insert(parent, atoi(token));
            }else if (token != NULL && strcmp(token, ":") != 0 && i == 0)
            {
                insert(root, atoi(token));
            }
        }
        i++;
    }
    fclose(f);
}

bool check_la(TreeNode *r)
{
    if (r->leftmostchild == NULL)
        return true;
    return false;
}

void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    if (check_la(root) == false)
    {
        printf("%d co cac cay con: ", root->data);
        TreeNode *tmp = root->leftmostchild;
        while (tmp != NULL)
        {
            printf("%d ", tmp->data);
            tmp = tmp->rightchild;
        }
        printf("\n");
        tmp = root->leftmostchild;
        while (tmp != NULL)
        {
            printTree(tmp);
            tmp = tmp->rightchild;
        }
    }
}

void freetree(TreeNode *r)
{
    if (r == NULL)
        return;
    TreeNode *p = r->leftmostchild;
    while (p != NULL)
    {
        TreeNode *sp = p->rightchild;
        freetree(p);
        p = sp;
    }
    free(r);
    r = NULL;
}

int main()
{
    char filename[100];
    printf("Nhap vao filename: ");
    scanf("%s", filename);
    Load(filename);
    printTree(root);
    freetree(root);
    return 0;
}

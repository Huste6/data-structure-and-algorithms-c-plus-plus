#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#define Max_Len 25
#define Max_Len1 100
typedef struct Tudien{
    char tiengviet[Max_Len];
    char tienganh[Max_Len];
}Tudien;
typedef struct TreeNode{
    Tudien data;
    struct TreeNode*left;
    struct TreeNode*right;
}TreeNode;
TreeNode*root=NULL;
TreeNode*makeTree(char*tiengviet,char*tienganh){
    TreeNode*newnode=(TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newnode->data.tiengviet,tiengviet);
    strcpy(newnode->data.tienganh,tienganh);
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int cmp(TreeNode*a,TreeNode*b)
{
    if(strcmp(a->data.tienganh,b->data.tienganh)>0) return 1;
    if(strcmp(a->data.tienganh,b->data.tienganh)<0) return -1;
    if(strcmp(a->data.tiengviet,b->data.tiengviet)>0) return 1;
    if(strcmp(a->data.tiengviet,b->data.tiengviet)<0) return -1;
    return 0;
}
TreeNode*insert(TreeNode*root,TreeNode*tmp)
{
    if(root==NULL) return tmp;
    int compare=cmp(root,tmp);
    if(compare>0){
        root->left=insert(root->left,tmp);
    }else if(compare<0)
    {
        root->right=insert(root->right,tmp);
    }
    return root;
}
void xulyfile(char *filename)
{
    FILE*f=fopen(filename,"r");
    if(f==NULL){
        printf("Not Found!\n");
        return;
    }
    while(!feof(f)){
        char tiengviet[Max_Len],tienganh[Max_Len];
        fscanf(f,"%s %s\n",tienganh,tiengviet);
        printf("%s %s\n",tienganh,tiengviet);
        TreeNode*tmp=makeTree(tiengviet,tienganh);
        root=insert(root,tmp);
    }
    fclose(f);
}
void destroyTree(TreeNode* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}
void chuyen_in_thuong(char*name)
{
    if (name == NULL || name[0] == '\0') {
        return;
    }
    for(int i=0;i<strlen(name);i++){
        name[i]=tolower(name[i]);
    }
}
TreeNode*find(TreeNode*root,char*tienganh)
{
    if(root==NULL) return NULL;
    if(strcmp(root->data.tienganh,tienganh)==0) return root;
    TreeNode*tmp=find(root->left,tienganh);
    if(tmp!=NULL) return tmp;
    return find(root->right,tienganh);
}

void inorder(TreeNode*root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%s %s\n",root->data.tienganh,root->data.tiengviet);
        inorder(root->right);
    }
}
int main()
{
    while(1){
        printf("---------------------------\n");
        printf("1.Nap du lieu!\n");
        printf("2.In cay nhi phan tim kiem!\n");
        printf("3.Them/Sua tu!\n");
        printf("4.Dich cau Anh-Viet\n");
        printf("5.Thoat!\n");
        printf("---------------------------\n");
        int cmd;scanf("%d",&cmd);
        getchar();
        if(cmd==1){
            xulyfile("test_case.txt");
            printf("Nap du lieu thanh cong!\n");
        }else if(cmd==2)
        {
            inorder(root);
        }else if(cmd==3)
        {
            char tienganh[Max_Len],tiengviet[Max_Len];
            printf("Nhap vao 1 tu tieng anh: ");scanf("%s",tienganh);
            TreeNode*tmp=find(root,tienganh);
            if(tmp!=NULL){
                char kt[2];
                printf("Ban muon nhap noi dung moi cho tu nay khong!\n");
                scanf("%s",kt);
                if(strcmp(kt,"y")==0){
                    printf("Nhap nghia tieng viet: ");scanf("%s",tiengviet);
                    strcpy(tmp->data.tiengviet,tiengviet);
                }else if(strcmp(kt,"n")==0){
                    continue;
                }
            }else if(tmp==NULL){
                printf("Nhap nghia tieng viet: ");scanf("%s",tiengviet);
                TreeNode*tp=makeTree(tiengviet,tienganh);
                root=insert(root,tp);
            }
        }else if (cmd == 4)
        {
            printf("Nhap cau tieng anh: ");
            char tienganh[Max_Len1];
            fgets(tienganh, sizeof(tienganh), stdin);
            tienganh[strcspn(tienganh, "\n")] = '\0';
            char sentence_copy[Max_Len1],sentence_copy1[Max_Len1];
            strcpy(sentence_copy, tienganh);
            strcpy(sentence_copy1, tienganh);
            char *token = strtok(tienganh, " ");
            while (token != NULL)
            {
                chuyen_in_thuong(token);
                printf("%s\n", token);
                token = strtok(NULL, " ");
            }
            char *token1 = strtok(sentence_copy, " ");
            while (token1 != NULL)
            {
                chuyen_in_thuong(token1);
                TreeNode *tmp = find(root, token1);
                if (tmp == NULL)
                {
                    printf("<thieu tu> ");
                }
                else if (tmp != NULL)
                {
                    printf("%s ", tmp->data.tiengviet);
                }
                token1 = strtok(NULL, " ");
            }
            printf("\n");
        }
        else if(cmd==5) break;
    }
    destroyTree(root);
    return 0;
}

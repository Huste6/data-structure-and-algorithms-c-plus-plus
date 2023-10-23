#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node{
    int row,col;
    int step;
    struct node*next;
    struct node*parent;
}node;
node*head,*tail;
node*listNode[MAX*MAX];
int szList=0;//so phan tu cua listNode
int A[MAX][MAX];
int n,m;
int r0,c0;
int visited[MAX][MAX];
const int dr[4]={1,-1,0,0};
const int dc[4]={0,0,1,-1};
node*finalNode;
node*makenode(int row,int col,int step,node*parent)
{
    node*Node=(node*)malloc(sizeof(node));
    Node->row=row;Node->col=col;Node->next=NULL;
    Node->parent=parent;
    Node->step=step;
    return Node;
}
void initQueue()
{
    head=NULL;tail=NULL;
}
int queueEmpty()
{
    return head==NULL && tail==NULL;
}
void PushQueue(node*Node)
{
    if(queueEmpty()){
        head=Node;tail=Node;
    }else{
        tail->next=Node;tail=Node;
    }
}
node*popQueue()
{
    if(queueEmpty()) return NULL;
    node*Node=head;head=head->next;
    if(head==NULL) tail=NULL;
    return Node;
}
void input()
{
    FILE*f=fopen("maze.txt","r");
    fscanf(f,"%d%d%d%d",&n,&m,&r0,&c0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            fscanf(f,"%d",&A[i][j]);
        }
    }
    fclose(f);
}
int legal(int row,int col)
{
    return A[row][col]==0 && !visited[row][col];
}
int target(int row,int col)
{
    return row<1 || row>n || col<1 || col>m;
}
void finalize()
{
    for(int i=0;i<szList;i++)
    {
        free(listNode[i]);
    }
}
void addList(node*Node)
{
    listNode[szList]=Node;
    szList++;
}

int main()
{
    //printf("MAZE\n");
    input();
    for(int r=1;r<=n;r++)
    {
        for(int c=1;c<=m;c++)
        {
            visited[r][c]=0;
        }
    }
    initQueue();
    node*startNode=makenode(r0,c0,0,NULL);
    addList(startNode);
    PushQueue(startNode);
    visited[r0][c0]=1;
    while(!queueEmpty())
    {
        node*Node=popQueue();
        //printf("POP (%d %d)\n",Node->row,Node->col);
        for(int k=0;k<4;k++)
        {
            int nr=Node->row+dr[k];
            int nc=Node->col+dc[k];
            if(legal(nr,nc)){
                visited[nr][nc]=1;
                node*newnode=makenode(nr,nc,Node->step+1,Node);
                addList(newnode);
                if(target(nr,nc)){
                    finalNode=newnode;break;
                }else{
                    PushQueue(newnode);
                }
            }
        }
        if(finalNode!=NULL) break;
    }
    node*s=finalNode;
    int cnt=0;
    while(s!=NULL){
        ///printf("(%d %d)",s->row,s->col);
        cnt++;
        s=s->parent;
    }
    printf("%d\n",cnt-1);
    finalize();
}

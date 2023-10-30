#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int n, m;
int* so_luong_o;

typedef struct Node {
    int currCap;
    struct Node* next;
} Node;

typedef struct Stack {
    int maxCap;
    Node* head;
    struct Stack* next1;
} Stack;

Stack* top = NULL;
Stack* parent = NULL;

Stack* make_stack(int x) {
    Stack* tmp = (Stack*)malloc(sizeof(Stack));
    tmp->maxCap = x;
    tmp->head = NULL;
    tmp->next1 = NULL;
    return tmp;
}

Node* make_Node(int x) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->currCap = x;
    newnode->next = NULL;
    return newnode;
}

int size_of_stack(Stack* tmp) {
    int cnt = 0;
    Node* head = tmp->head;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

int FullStack(Stack* tmp) {
    return m == size_of_stack(tmp);
}

int IsEmpty() {
    return top == NULL;
}

void push_Stack(int x) {
    if (IsEmpty()) {
        parent = make_stack(x);
        top = parent;
    } else {
        Stack* tmp = make_stack(x);
        tmp->next1 = top;
        top = tmp;
    }
}

void push_Node_to_Each_Stack(Stack* tmp, int x) {
    Node* head1 = tmp->head;
    if (head1 == NULL) {
        Node* newnode = make_Node(x);
        tmp->head = newnode;
        return;
    }
    Node* newnode = make_Node(x);
    head1->next = newnode;
    tmp->head = newnode;
}

void solve(int x) {
    int abs1[n];
    int res = 0,res1=0;
    Stack* tmp = parent;
    //Node* node = tmp->head;
    int min_abs = INT_MAX;
    while (tmp != NULL) {
        if(so_luong_o[res]>0 && tmp->maxCap==x){
            so_luong_o[res]--;
            push_Node_to_Each_Stack(tmp,x);
            return;
        }
        if(x>tmp->maxCap){
            res1++;
        }
        abs1[res]=tmp->maxCap-x;
        if(min_abs>abs1[res] && abs1[res]>0){
            min_abs=abs1[res];
        }
        res++;
        tmp = tmp->next1;
    }

    if(res1==n) return;

    res=0;
    tmp=parent;
    while(tmp!=NULL){
        if(min_abs==tmp->maxCap-x){
            push_Node_to_Each_Stack(tmp,x);
            so_luong_o[res]--;
        }
        tmp=tmp->next1;
        res++;
    }
}

void free_stack(Stack* s) {
  Node* curr = s->head;
  Node* next;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }
  free(s);
}

int main() {
    scanf("%d%d", &n, &m);
    //so_luong_o = (int*)malloc(sizeof(int) * n);
    so_luong_o[n]={m};
    //Stack*root=top
    for(int i=0;i<n;i++){
        printf("%d ",so_luong_o[i]);
    }
    /*for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push_Stack(x);
    }

    int k;
    scanf("%d", &k);
    int a[k];

    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
        solve(a[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(so_luong_o[i]>0){
            //cnt++;
            printf("%d\n",so_luong_o[i]);
        }
    }
    //printf("%d",cnt);

    free(so_luong_o);

    Stack* curr = top;
    Stack* next;
    while (curr != NULL) {
      next = curr->next1;
      free_stack(curr);
      curr = next;
    }*/

    return 0;
}

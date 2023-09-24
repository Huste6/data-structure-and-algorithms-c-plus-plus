#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next=NULL;
};
node *makenode(int x){
    node *newnode = new node;
    newnode->next = NULL;
    newnode->data = x;
    return newnode;
}
node *addelement(node *head, int x){
    node *tmp = makenode(x);
    head->next = tmp;
    return tmp;
}
void duyet(node *head){
    node *tmp = head;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}
bool timphantu(node *&head, int k){
    node *tmp = head;
    while(tmp != NULL){
        if(tmp->data == k){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}
void addlast(node *&head, int k){
    node *newnode = makenode(k);
    node *tmp = head;
    if(head == NULL){
        head = newnode;
        return ;    
    }
    if(timphantu(tmp, k)) return;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newnode;
}
void addfirst(node *&head, int k){
    if(timphantu(head, k)) return;
    node *newnode = makenode(k);
    newnode->next = head;
    head = newnode;
}
void addafter(node *&head, int u, int v){
    if(timphantu(head, v) == false) return;
    if(timphantu(head,u)) return;
    node *newnode = makenode(u);
    node *tmp = head;
    if(head == NULL){
        head = newnode;
        return;
    }
    while(tmp != NULL && tmp->data != v){
        tmp = tmp->next;
    }
    if(tmp == NULL) return;
    newnode->next = tmp->next;
    tmp->next = newnode;
}
void addbefore(node *&head, int u, int v){
    if(timphantu(head, v) == false) return;
    if(timphantu(head,u)) return;
    node *newnode = makenode(u);
    if(head == NULL){
        head = newnode;
        return;
    }
    node *prev = NULL;
    node *cur = head;
    while(cur != NULL && cur->data != v){
        prev = cur;
        cur = cur->next;
    }
    if(cur == NULL) return;
    if(prev == NULL){
        newnode->next = head;
        head = newnode;
    }
    else{
        newnode->next = cur;
        prev->next = newnode;
    }
}
void remove(node *&head, int k){
    node *tmp = head;
    node *prev = NULL;
    while(tmp != NULL && tmp->data != k){
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL) return;
    if(prev == NULL){
        head = tmp->next;
    }
    else{
        prev->next = tmp->next;
    }
    delete tmp;
}
void reverse(node *&head){
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    node *head = makenode(x);
    node *tmp = head;
    for(int i = 1; i < n; i++){
        cin >> x;
        tmp = addelement(tmp, x);
    }
    string s;
    int k, k1;
    while(cin >> s){
        if(s == "addlast"){
            cin >> k;
            addlast(head, k);
        }
        else if(s == "addfirst"){
            cin >> k;
            addfirst(head, k);
        }
        else if(s == "addafter"){
            cin >> k >> k1;
            addafter(head, k, k1);
        }
        else if(s == "addbefore"){
            cin >> k >> k1;
            addbefore(head, k, k1);
        }
        else if(s == "remove"){
            cin >> k;
            remove(head, k);
        }
        else if(s == "reverse"){
            reverse(head);
        }
        else if(s == "#"){
            break;
        }
    }
    duyet(head);
    return 0;
}

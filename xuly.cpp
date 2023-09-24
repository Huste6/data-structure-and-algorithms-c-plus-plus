#include<iostream>
#include<cstring>
using namespace std;
typedef struct Tnode{
    int key;
    Tnode *right;
    Tnode *left;
} Node;

Node *root;
int result;

Node *makeNode(int v){
    Node *tmp= new Node;
    tmp->key=v;
    tmp->right=nullptr;
    tmp->left=nullptr;
    return tmp;
}

int find(int v, Node *r){
    if (r==nullptr) return 0;
    if (r->key==v) return 1;
    if (v<r->key) return find (v,r->left);
    else return find (v,r->right);
}
Node* findmin(Node *r){
    if (r==nullptr) return nullptr;
    Node *tmp=findmin(r->left);
    if (tmp!=nullptr) return tmp;
    else return r;
}

Node* insert(int v, Node*r){
    if (r==nullptr) {
        r=makeNode(v);
        result=1;
        return r;
    }
    if (r->key==v) {
        result=0;
        return r;
    }
    if (v<r->key) {
        r->left=insert (v,r->left);
    }
    else {
        r->right=insert (v,r->right);
    }
    return r;
}

Node* remove(int v, Node *r){
    if (r==nullptr){
        result=0;
        return nullptr;
    }
    if (r->key==v) {
        result=1;
        if (r->right!=nullptr) {
            if (r->left==nullptr) {
                Node *tmp=r;
                r=r->right;
                delete tmp;
            }
            else {
                Node *tmp=findmin(r->right);
                r->key=tmp->key;
                r->right=remove(tmp->key,r->right);
            }
        }
        else {
            Node *tmp=r;
            if (r->left==nullptr) {
                delete tmp;
            }
            else {
                r=r->left;
                delete tmp;
            }
        }
        return r;
    }
    else {
        if (v<r->key) r->left=remove(v,r->left);
        else r->right=remove(v,r->right);
        return r;
    }
}

void inorder(Node *r){
    if (r==nullptr) return;
    inorder(r->left);
    cout << r->key << " ";
    inorder(r->right);
}

void process(){
    int a;
    while (1){
        cin >> a;
        if (a==-1) break;
        root=insert(a,root);
    }
char cmd[30];
    do {
        cin >> cmd;
        if (!strcmp(cmd,"$remove")){
            cin >> a;
            root=remove(a,root);
            cout << result << endl;
        }
        else if (!strcmp(cmd,"$find")){
            cin >> a;
            cout << find(a,root) << endl;
        }
        else if (!strcmp(cmd,"$insert")){
            cin >> a;
            root=insert(a,root);
            cout << result << endl;
        }
    } while (strcmp(cmd,"*")!=0);
}
int main (){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    root=nullptr;
    process();
    return 0;
}


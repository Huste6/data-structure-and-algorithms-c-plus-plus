#include<bits/stdc++.h> 
using namespace std; 

struct node{
    int data;
    struct node* next;
};

node *makenode(int x){
    node *newnode = new node;
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

node *addelement(node* p, int x){
    node *temp = makenode(x);
    p->next = temp;
    return temp;
}

int timphantu(node **head,int k){
    node *tmp=*head;
    for(int i=0;i<k;i++){
        tmp=tmp->next;
    }
    return tmp->data;
}

void duyet(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout << endl;
}

void deletebigger(node **head, int k){
    node *tmp = *head;
    node *ans = NULL;
    
    while(tmp != NULL){
        if(tmp->data <= k){
            node *newnode = makenode(tmp->data);
            
            if(ans == NULL){
                ans = newnode;
            }
            else{
                node *temp = ans;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }
        
        tmp = tmp->next;
    }
    duyet(ans);
}

int main(){
    int n, x, k; 
    cin >> n; 
    cin >> x; 
    node *head = makenode(x); 
    node *tmp = head; 
    
    for (int i = 1; i < n; i++){
        cin >> x; 
        tmp = addelement(tmp, x); 
    } 
    
    cin >> k; 
    
    int x1 = timphantu(&head, k); 
    deletebigger(&head,x1);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
//tao danh sach lien ket yeu cau xoa phan tu o vi tri k cho truoc
struct node{
    int data;
    struct node *next;
};

node *makenode(int x){
    node *head = new node();
    head->data = x;
    head->next = nullptr;
    return head;
}

void duyet(node *head){
    node *tmp = head;
    while(tmp != nullptr){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}

node *addelement(node *head, int x){
    node *tmp = makenode(x);
    head->next = tmp;
    return tmp;
}

void deletehead(node **head){
	if(*head==NULL) return;
    node *tmp = *head;
    *head = (*head)->next;
    delete(tmp);
    //free(tmp); trong c
}

void deletetail(node **head){
	if(*head==NULL) return;
    node *tmp = *head;
    if(tmp->next==NULL){
    	*head=NULL;delete(tmp);
    	return;
	}
    while(tmp->next->next != nullptr){
        tmp = tmp->next;
    }
    delete(tmp->next);
    tmp->next = nullptr;
}

void deleteat(node **head, int k){
    node *tmp = *head;
    int n=size(*head);
    if(1<k||k>n-1) return;
    else{
		for(int i = 0; i < k-1; i++){
	        tmp = tmp->next;
	    }
	    node *toBeDeleted = tmp->next;
	    tmp->next = tmp->next->next;
	    delete toBeDeleted;}
}

int main(){
    int n, x, k;
    cin >> n >> x;
    node *head = makenode(x);
    node *current = head;

    for(int i = 1; i < n; i++){
        cin >> x;
        current = addelement(current, x);
    }

    cin >> k;

    if(k == 0){
        deletehead(&head);
    }
    else if(k == n-1){
        deletetail(&head);
    }
    else{
        deleteat(&head, k);
    }

    duyet(head);
    return 0;
}



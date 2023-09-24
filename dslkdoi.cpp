
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

node *makenode(int x){
	node *newnode = new node;
	newnode->data = x;
	newnode->next = nullptr;
	newnode->prev = nullptr;
	return newnode;
}

void duyet(node *head){
	while(head != nullptr){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void pushfront(node **head, int x){
	node *newnode = makenode(x);
	newnode->next = *head;
	if(*head != nullptr){
		(*head)->prev = newnode;
	}
	*head = newnode;
}

void pushback(node **head, int x){
	node *newnode = makenode(x);
	if(*head == nullptr){
		*head = newnode;
		return;
	}
	node *tmp = *head;
	while(tmp->next != nullptr){
		tmp = tmp->next;
	}
	tmp->next = newnode;
	newnode->prev = tmp;
}

void pushat(node **head, int k, int x){
	node *newnode = makenode(x);
	if(*head == nullptr){
		*head = newnode;
		return;
	}
	int n=sizeof(*head);
	if(k<1||k>n){
		cout<<"vi tri chen khong hop le!\n"<<endl;
		return;
	}
	if(k==1){
		pushfront(head,x);
	}
	node *tmp = *head;
	for(int i = 1; i <= k-1; i++){
		tmp = tmp->next;
	}
	newnode->next = tmp->next;
	if(tmp->next != nullptr){
		tmp->next->prev = newnode;
	}
	tmp->next = newnode;
	newnode->prev = tmp;
}

void addelement(node *&head, int x){
	node *newnode = makenode(x);
	if (head == NULL) {
        head = newnode;
        return;
    }
	node *tmp = head;
	while(tmp->next != nullptr){
		tmp = tmp->next;
	}
	tmp->next = newnode;
	newnode->prev = tmp;
}

int main(){
	node *head = nullptr;
	while(1){
		cout << "---------------------\n";
		cout << "0.nhap vao mang\n";
		cout << "1.them vao dau\n";
		cout << "2.them vao cuoi\n";
		cout << "3.them vao giua\n";
		cout << "4.duyet\n";
		cout << "5.thoat\n";
		cout << "---------------------\n";
		cout << "nhap lua chon: ";
		int lc;
		cin >> lc;
		if(lc == 1){
			int x;
			cout << "nhap x: ";
			cin >> x;
			pushfront(&head,x);
		}else if (lc == 2){
			int x;
			cout << "nhap x: ";
			cin >> x;
			pushback(&head,x);
		}else if(lc == 3){
			int x;
			cout << "nhap x: ";
			cin >> x;
			int k;
			cout << "nhap k: ";
			cin >> k;
			pushat(&head,k,x);
		}else if(lc == 4){
			duyet(head);
			cout << endl;
		}else if(lc == 0){
			int x;
			cout << "nhap so luong phan tu: ";
			cin >> x;
			int k;
			cout << "nhap gia tri cac phan tu: ";
			for(int i = 0; i < x; i++){
				cin >> k;
				if(i == 0){
					head = makenode(k);
				}else{
					addelement(head, k);
				}
			}
		}else{
			break;
		}
	}
	return 0;
}



#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};
node *createNode(int x){
    node *temp = new node;
    temp->next = temp;
    temp->data = x; 
    return temp;
}
void printList(node *l, int k){
	node *p = l;
	for (int i = 0; i < k; i++){
		p = p->next;
	}
	cout << p->data << " ";
	node *p2 = p->next;
	while (p2 != p){
		cout << p2->data << " ";
		p2 = p2->next;
	}
}
void printList1(node*head){
	node*tmp=head;
	if(head!=nullptr){
		do{
			cout<<tmp->data<<" ";
			tmp=tmp->next;
		}while(tmp!=head);
	}
	cout<<endl;
}
node *addTail(node *l, int x){
	node *p = l;
	while (p->next != l){
		p = p->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->next = l;
	p->next = temp;
	return l;
}
void pushbefore(node*&head,int x){
	node*newnode=new node;
	newnode->data=x;
	newnode->next=head;
	if(head!=nullptr){
		//find the node before head and update next of it
		node*tmp=head;
		while(tmp->next!=head){
			tmp=tmp->next;
		}
		tmp->next=newnode;
	}else{
		newnode->next=newnode;
	}
	head=newnode;
}
void addEnd(node*&head,int key){
	if(head==nullptr){
		node*newnode=new node;
		newnode->data=key;
		newnode->next=newnode;
		return;
	}
	node *newnode1=new node;
	newnode1->data=key;
	node*tmp=head;
	while(tmp->next!=head){
		tmp=tmp->next;
	}
	newnode1->next=head;
	tmp->next=newnode1;
}
//item la vi tri cho truc 
// key la vi tri can them vao sau item

void addMid(node*&head,int key,int item){
	if(head==nullptr){
		node*newnode=new node;
		newnode->data=key;
		newnode->next=newnode;
		head=newnode;
		return;
	}
	node *tmp=head->next;
	do{
		if(tmp->data==item){
			node *newnode=new node;
			newnode->data=key;
			newnode->next=tmp->next;
			tmp->next=newnode;
			return;	
		}
		tmp=tmp->next;
	}while(tmp!=head);
}
// them key vao truoc item
void addMid1(node*&head,int key,int item){
	if(head==nullptr){
		node*newnode=new node;
		newnode->data=key;
		newnode->next=newnode;
		head=newnode;
		return;
	}
	node *tmp=head->next;
	node*prev;
	do{
		prev=tmp;
		tmp=tmp->next;
		if(tmp->data==item){
			node*newnode=new node;
			newnode->data=key;
			prev->next=newnode;
			newnode->next=tmp;
			return;
		}
	}while(tmp!=head);
}
void deletenode(node*&head,int key){
	if(head==nullptr) return;
	//if head contain only a single node
	if(head->data==key &&head->next==head){
		delete(head);
		head=nullptr;return;
	}
	node*tmp=head;
	node*prev;
	//if head if to be deleted
	if(head->data==key){
		while(tmp->next!=head){
			tmp=tmp->next;
		}
		tmp->next=head->next;
		delete(head);
		head=tmp->next;
		return;
	}
	//if node to be deleted is not found or the end of list is not reach
	while(tmp->next!=head && tmp->next->data!=key){
		tmp=tmp->next;
	}
	if(tmp->next->data==key){
		prev=tmp->next;
		tmp->next=prev->next;
		delete(prev);
	}else{
		cout<<"Given node is not found in the list!!";
	}
}
int main(){
	int n, x, k;
	cin >> n;
	cin >> x;
	node *l = createNode(x);
	node *p = l;
	for (int i = 1; i < n; i++){
		cin >> x;
		//pushbefore(l, x);
		l=addTail(l,x);
	}
	pushbefore(l,10);
	deletenode(l,3);
	addEnd(l,2);
	addMid(l,3,1);
	addMid1(l,11 ,3); 
	//cin >> k;
	//printList(l,k);
	printList1(l);
	return 0;
}

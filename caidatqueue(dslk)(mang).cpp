#include<bits/stdc++.h>
using namespace std;
/*bang mang
int a[1000],maxN=1000;
int n=0;
int size(){
	return n;
}
bool empty(){
	return n==0;
}
void push(int x){
	if(n==maxN) return;
	a[n]=x;++n;
}
void pop(){
	if(n==0) return;
	for(int i=0;i<n-1;i++){
		a[i]=a[i+1];
	}
	--n;
}
int front(){
	return a[0];
}*/
//bang dslk
//enqueue: them 1 phan tu vao cuoi hang doi
//dequeue: Xoa 1 phan tu khoi dau hang doi
//IsEmpty: Kiem tra xem hang doi co trong hay khong
//IsFull: Kiem tra hang doi da day hay chua
//Peek(Front): Lay gia tri dau hang doi ma khong can loai bo no
//Rear:Lay gia tri phia cuoi hang doi ma khong can loai bo no
struct node{
	int data;
	struct node *next;
};
node *makenode(int x){
	node *newnode =new node();
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}
void push(node **queue,int x){
	node *newnode=makenode(x);
	if(*queue==NULL){
		*queue=newnode;return;
	}
	node *tmp=*queue;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next=newnode;
}
void pop(node **queue){
	if(*queue==NULL) return;
	node *tmp=*queue;
	(*queue)=(*queue)->next;
	delete(tmp);//free(tmp);
}
int size(node *queue){
	int dem=0;
	while(queue!=NULL){
		++dem;
		queue=queue->next;
	}
	return dem;
}
bool empty(node *queue){
	return queue==NULL;
}
int front(node *queue){
	return queue->data;
}
void duyet(node *queue){
	while(queue!=NULL){
		cout<<queue->data<<" ";
		queue=queue->next;
	}
}
int main(){
	node *queue=NULL;
	while(1){
		cout<<"-------------------\n";
		cout<<"1.Push\n";
		cout<<"2.Pop\n";
		cout<<"3.Front\n";
		cout<<"4.Size\n";
		cout<<"5.Empty\n";
		cout<<"6.Duyet\n";
		cout<<"0.Thoat!\n";
		cout<<"--------------------\n";
		int lc;cout<<"Nhap luu chon: ";cin>>lc;
		if(lc==1){
			int x;cin>>x;
			push(&queue,x);
		}else if(lc==2){
			pop(&queue);
		}else if(lc==3){
			cout<<front(queue)<<endl;
		}else if(lc==4){
			cout<<size(queue)<<endl;
		}else if(lc==5){
			if(empty(queue)) cout<<"Empty!\n";
			else cout<<"not empty!\n";
		}else if(lc==6){
			duyet(queue);
			cout<<endl;
		}else{
			break;
		}
	}
}

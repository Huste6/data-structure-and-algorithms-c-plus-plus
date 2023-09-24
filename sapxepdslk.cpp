#include<bits/stdc++.h>

using namespace std;
struct Sinhvien{
	string name;
	double gpa;
	Sinhvien(){
		
	}
	Sinhvien(string ten,double diem){
		name=ten;
		gpa=diem;
	}
};
struct node{
	Sinhvien data;
	struct node *next;
};
node *makenode(Sinhvien s){
	node *newnode=new node;
	newnode->data=s;
	newnode->next=NULL;
	return newnode;
}
void pushback(node **head,Sinhvien s){
	node *newnode=makenode(s);
	if(*head==NULL){
		*head=newnode;return;
	}
	node *tmp=*head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next=newnode;
}
void duyet(node *head){
	while(head!=NULL){
		cout<<head->data.name<<" "<<fixed<<setprecision(2)<<head->data.gpa<<endl;
		head=head->next;
	}
}
void sapxep(node **head){
	for(node *i=*head;i!=NULL;i=i->next){
		node *minnode=i;
		for(node *j=i->next;j!=NULL;j=j->next){
			if(minnode->data.gpa > j->data.gpa){
				minnode=j;
			}else if(minnode->data.gpa == j->data.gpa){
				if(minnode->data.name > j->data.name){
					minnode=j;
				}
			}
		}
		swap(minnode->data,i->data);
	}
}

/*
struct node{
	int data;
	struct node *next;
};
node *makenode(int x){
	node *newnode=new node();
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}
void pushback(node **head,int x){
	node *newnode=makenode(x);
	if(*head==NULL){
		*head=newnode;return;
	}
	node *tmp=*head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next=newnode;
}
void duyet(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
//sap xep phan data
//sap xep chon
void sapxep(node **head){
	for(node *i=*head;i!=NULL;i=i->next){
		node *minnode=i;
		for(node *j=i->next;j!=NULL;j=j->next){
			if(minnode->data>j->data){
				minnode=j;
			}
		}
		swap(minnode->data,i->data);
	}
}
int main(){
	node *head=NULL;
	int a[]={10,9,1,2,4,5,3,7,8,6};
	for(int i=0;i<10;i++){
		pushback(&head,a[i]);
	}
	sapxep(&head);
	duyet(head);
	return 0;
}*/
int main(){
	node *head=NULL;
	Sinhvien s("teo",3.5);
	Sinhvien t("ti",3.8);
	Sinhvien u("long",3.5);
	Sinhvien v("hai",2.8);
	pushback(&head,s);
	pushback(&head,t);
	pushback(&head,u);
	pushback(&head,v);
	sapxep(&head);
	duyet(head);
}

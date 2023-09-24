/*
#include <iostream>
using namespace std;

int n = 0, st[10001];

void push(int x) {
    st[n] = x;
    ++n;
}

void pop() {
    if (n >= 1) {
        --n;
    }
}

int top() {
    return st[n - 1];
}

int size() {
    return n;
}

int main() {
    while (1) {
        cout << "--------------\n";
        cout << "1.push\n";
        cout << "2.pop\n";
        cout << "3.top\n";
        cout << "4.size\n";
        cout << "0.thoat\n";
        cout << "--------------\n";
        int lc;
        cin >> lc;
        if (lc == 1) {
            int x;
            cout << "nhap x: ";
            cin >> x;
            push(x);
        } else if (lc == 2) {
            pop();
        } else if (lc == 3) {
            if (n == 0) cout << "empty\n";
            cout << top() << endl;
        } else if (lc == 4) {
            cout << size() << endl;
        } else {
            break;
        }
    }
    return 0;
}*/
//dung dslk
#include<bits/stdc++.h>
using namespace std;
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
void push(node **head,int x){
	node *newnode=makenode(x);
	newnode->next=(*head)->next;
	//cap nhat lai con tro head thanh con tro newnode
	*head=newnode;
}
void pop(node **head){
	if(*head!=NULL){
		node *tmp=*head;
		*head=tmp->next;
		delete(tmp);
		//free(tmp);
	}
}
int top(node **head){
	if(*head!=NULL){
		return (*head)->data; 
	}
}
int size(node *head){
	int dem=0;
	while(head!=NULL){
		++dem;
		head=head->next;
	}
	return dem;
}
int main(){
	node *st=NULL;
	while (1) {
        cout << "--------------\n";
        cout << "1.push\n";
        cout << "2.pop\n";
        cout << "3.top\n";
        cout << "4.size\n";
        cout << "0.thoat\n";
        cout << "--------------\n";
        int lc;
        cin >> lc;
        if (lc == 1) {
            int x;
            cout << "nhap x: ";
            cin >> x;
            push(&st,x);
        } else if (lc == 2) {
            pop(&st);
        } else if (lc == 3) {
            if (st == NULL) cout << "empty\n";
            cout << top(&st) << endl;
        } else if (lc == 4) {
            cout << size(st) << endl;
        } else {
            break;
        }
    }
    return 0;
}
/*

#include<bits/stdc++.h> 
using namespace std; 

class mystack { 
private: 
    int arr[1000]; 
    int top; 
public: 
    mystack(){top=-1;} 
    int pop(); 
    void push(int); 
}; 

//function to push an integer into the stack. 
void mystack :: push(int x) { 
    if (top >= 1000) { // Ki?m tra ngan x?p d� d?y chua
        cout << "Stack Overflow" << endl; // Th�ng b�o ngan x?p d� d?y
        return; 
    } 
    arr[++top] = x; // Tang top l�n r?i d?y gi� tr? v�o ngan x?p
} 

//function to remove an item from top of the stack. 
int mystack :: pop() { 
    if (top < 0) { // Ki?m tra ngan x?p d� r?ng chua
        //cout << "Stack Underflow" << endl; // Th�ng b�o ngan x?p d� r?ng
        return -1; 
    } 
    int x = arr[top--]; // L?y gi� tr? ph?n t? t? d?nh ngan x?p v� gi?m top di 1
    return x; // Tr? v? gi� tr? ph?n t? v?a l?y ra
}

int main() { 
    int n; 
    cin >> n; // Nh?p s? ph?n t? th?c thi tr�n ngan x?p
    
    mystack s; // Kh?i t?o d?i tu?ng ngan x?p
    vector<int> vt;
    for (int i = 0; i < n; i++) { 
        string operation; 
        cin >> operation; // Nh?p thao t�c
        
        if (operation == "push") { 
            int number; 
            cin >> number; // Nh?p gi� tr? push v�o
            
            s.push(number); // Th?c hi?n thao t�c push v�o ngan x?p
        } 
        else if (operation == "pop") { 
            int result = s.pop(); // Th?c hi?n thao t�c pop t? ngan x?p
            vt.push_back(result);
        } 
    } 
    if(vt.size()==0){
      cout<<" ";
    }else{
      for(auto x:vt){
        cout<<x<<" ";
      }
    }
    return 0; 
}
*/


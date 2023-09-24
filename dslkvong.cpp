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
int main(){
	int n, x, k;
	cin >> n;
	cin >> x;
	node *l = createNode(x);
	node *p = l;
	for (int i = 1; i < n; i++){
		cin >> x;
		l = addTail(l, x);
	}
	cin >> k;
	printList(l, k);
	return 0;
}

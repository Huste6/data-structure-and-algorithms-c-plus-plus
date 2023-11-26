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
//tim node thu k tu cuoi len
node *findNode(node*head,int k){
	node*slow=head;
	node*fast=head;
	for(int i=0;i<k;i++){
		fast=fast->next;
	}
	while(fast!=nullptr){
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}
//hoan doi node theo cap 1->2->3->4 => 2->1->4->3
node*hoandoinodetheocap1(node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    node*dummy=head->next;
    node*tmp=nullptr;
    while(head!=nullptr && head->next!=nullptr){
		if(tmp!=nullptr){
			tmp->next=head->next;
		}
		tmp=head;
		node*newnode=head->next->next;
		head->next->next=head;
    	head->next=newnode;
    	head=newnode;
	}
	return dummy;
}
//cach 2
void hoandoinodetheocap1(node*&head){
	if (head == nullptr || head->next == nullptr) {
        return;
    }
    node*prev=nullptr;
    node*tmp=head;
    node*next=nullptr;
    while(tmp!=nullptr && tmp->next!=nullptr){
    	next=tmp->next;
    	tmp->next=next->next;
    	next->next=tmp;
		prev=tmp;
		tmp=tmp->next;
	}
}
// tim mid cua node
void printMid(node*&head){
  	int length=length1(head);
  	if(length%2!=0){
    	node*slow=head;
    	node*fast=head;
    	while(fast!=NULL&&fast->next!=NULL){
      		slow=slow->next;
      		fast=fast->next->next;
    	}
    	cout<<slow->data;
    	return;
  	}else{
    	node*slow=head;
	    node*fast=head->next;
	    while(fast!=NULL&&fast->next!=NULL){
	      slow=slow->next;
	      fast=fast->next->next;
	    }
	    cout<<slow->data<<" "<<slow->next->data;
	    return;
  	}
}
//dao nguoc daon con trong node
void reverse(node*& head, int l, int r){
  if(l == r) return;
  node* tmp = head;
  node* leftNode = head;
  node* rightNode = head;
  node* prevLeft = NULL;
  node* nextRight = NULL;
  int i = 1;
  while(i < l){
    prevLeft = leftNode;
    leftNode = leftNode->next;
    i++;
  }
  i = 1;
  while(i < r){
    rightNode = rightNode->next;
    i++;
  }
  nextRight = rightNode->next;
  node* current = leftNode;
  node* prev = NULL;
  node* next = NULL;
  while(current != nextRight){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  if(prevLeft != NULL){
    prevLeft->next = rightNode;
  }
  else{
    head = rightNode;
  }
  leftNode->next = nextRight;
}
//xoa cac phan tu trung nhau
//vd: 1->1->1->2->2->3 => 1->2->3
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = head;
        ListNode* prev = nullptr;

        while (tmp != nullptr) {
            prev = tmp;
            tmp = tmp->next;

            while (tmp != nullptr && prev->val == tmp->val) {
                tmp = tmp->next;
            }

            if (tmp != nullptr && tmp->val != prev->val) {
                prev->next = tmp;
                prev = tmp;
            } else if (tmp == nullptr) {
                prev->next = nullptr;
            }
        }

        return head;
    }
//xoa cac phan tu trung nhau 2
//vd : 1->1->1->2->3->3->4->4->5
//output: 2->5
ListNode* deleteDuplicates(ListNode* head) {
        ListNode*tmp=head;
        ListNode*prev=NULL;
        ListNode*prev_prev=prev;
        while(tmp!=NULL){
            prev_prev=prev;
            prev=tmp;
            tmp=tmp->next;
            if(tmp!=NULL && tmp->val==prev->val){
                while(tmp != nullptr && (tmp->val == prev->val || (tmp->next != nullptr && tmp->next->val == tmp->val))){
                    prev=tmp;
                    tmp=tmp->next;
                }
                if(prev_prev==NULL){
                    head=tmp;
                }else{
                    prev_prev->next=tmp;
                }
            }

        }
        return head;
    }
//di chuyen sang phai k don vi
ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }

        int length = 1; // Start from 1 to account for the original head
        ListNode* tmp = head;
        while (tmp->next) {
            length++;
            tmp = tmp->next;
        }

        // Convert singly linked list into circular linked list
        tmp->next = head;

        k = k % length;
        if (k == 0) {
            tmp->next = nullptr; // No rotation needed
            return head;
        }

        k = length - k; // Find the new head position

        while (k--) {
            tmp = tmp->next;
        }

        head = tmp->next;
        tmp->next = nullptr; // Set the new tail's next to null

        return head;
    }
//dao theo cap
ListNode* swapPairs(ListNode* head) {
        if(head==NULL|| head->next==NULL) return head;
        ListNode*dummyNode=new ListNode();
        ListNode*prevNode=dummyNode;
        ListNode*currNode=head;
        while(currNode!=NULL && currNode->next!=NULL){
            prevNode->next=currNode->next;
            currNode->next=prevNode->next->next;
            prevNode->next->next=currNode;
            prevNode=currNode;
            currNode=currNode->next;
        }
        return dummyNode->next;
    }
//xoa 1 phan tu vi tri k tu cuoi len
int countNodes(ListNode* head) {
        int count = 0;
        ListNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalNodes = countNodes(head);
        int targetIndex = totalNodes - n;

        if (targetIndex == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* current = head;
        ListNode* prev = nullptr;
        int currentIndex = 0;

        while (currentIndex < targetIndex) {
            prev = current;
            current = current->next;
            currentIndex++;
        }

        prev->next = current->next;
        delete current;

        return head;
    }
//add two ll
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr) {
            int sum = carry;

            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum = sum % 10;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
        }

        if(carry == 1) {
            ptr->next = new ListNode(1);
        }

        return result->next;
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
    /*
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
    }*/
    head=hoandoinodetheocap1(head);
    duyet(head);
    return 0;
}

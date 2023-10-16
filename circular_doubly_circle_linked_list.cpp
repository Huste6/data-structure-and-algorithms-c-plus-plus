#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void insertEnd(node*& head, int val) {
    if (head == nullptr) {
        node* newnode = new node;
        newnode->data = val;
        newnode->next = newnode->prev = newnode;
        head = newnode;
        return;
    }
    node* last = head->prev;
    node* newnode = new node;
    newnode->data = val;
    newnode->prev = last;
    newnode->next = head;
    last->next = newnode;
    head->prev = newnode;
}

void insertBegin(node*& head, int val) {
    if (head == nullptr) {
        insertEnd(head, val);
        return;
    }
    node* last = head->prev;
    node* newnode = new node;
    newnode->data = val;
    newnode->prev = last;
    newnode->next = head;
    last->next = head->prev = newnode;
    head = newnode;
}

//insert val1 after val2
void insertAfter(node*& head, int val1, int val2) {
    if (head == nullptr) {
        insertEnd(head, val1);
        return;
    }
    node* tmp = head;
    do {
        if (tmp->data == val2) {
            node* newnode = new node;
            newnode->data = val1;
            newnode->next = tmp->next;
            newnode->prev = tmp;
            tmp->next->prev = newnode;
            tmp->next = newnode;
            return;
        }
        tmp = tmp->next;
    } while (tmp != head);
}

void printList(node* head) {
    node* tmp = head;
    if (head != nullptr) {
        do {
            cout << tmp->data <<" ";
            tmp = tmp->next;
        } while (tmp != head);
    }
    cout << endl;
}

int main() {
    node* head = nullptr;
    insertEnd(head, 5);
    insertBegin(head, 4);
    insertEnd(head, 7);
    insertEnd(head, 8);
    insertAfter(head, 6, 5);
    printList(head);
    return 0;
}

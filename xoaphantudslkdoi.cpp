
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* pre;
};

node* makenode(int x) {
    node* newnode = new node;
    newnode->data = x;
    newnode->next = nullptr;
    newnode->pre = nullptr;
    return newnode;
}

void duyet(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void addelement(node*& head, int x) {
    node* newnode = makenode(x);
    if (head == nullptr) {
        head = newnode;
        return;
    }
    node* tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newnode;
    newnode->pre = tmp;
}

void popfront(node** head) {
    if (*head == nullptr) return;
    node* tmp = *head;
    *head = (*head)->next;
    if (*head != nullptr) {
        (*head)->pre = nullptr;
    }
    delete(tmp);
}

void popback(node** head) {
    if (*head == nullptr) return;
    node* tmp = *head;
    if (tmp->next == nullptr) {
        *head = nullptr;
        delete(tmp);
        return;
    }
    while (tmp->next->next != nullptr) {
        tmp = tmp->next;
    }
    delete(tmp->next);
    tmp->next = nullptr;
}

void popat(node** head, int k) {
    node* tmp = *head;
    int n = 0;
    while (tmp != nullptr) {
        n++;
        tmp = tmp->next;
    }
    if (k < 1 || k > n - 1) return;
    tmp = *head;
    for (int i = 0; i < k - 1; i++) {
        tmp = tmp->next;
    }
    node* needdelete = tmp->next;
    tmp->next = needdelete->next;
    if (tmp->next != nullptr) {
        tmp->next->pre = tmp;
    }
    delete(needdelete);
}

int main() {
    int n, x;
    cin >> n;
    node* head = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> x;
        addelement(head, x);
    }
    // k is the position, x is the value to be inserted
    int k;
    cin >> k >> x;
    if (k < 0 || k > n) {
        return -1;
    }
    else if (k == 0) {
        popfront(&head);
    }
    else if (k == n) {
        popback(&head);
    }
    else {
        popat(&head, k);
    }
    duyet(head);
    return 0;
}



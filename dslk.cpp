#include <iostream>
using namespace std;

struct sinhvien {
    string name;
    string lop;
    double gpa;
};

struct node {
    int data;
    struct node* next; // link
};

typedef struct node node; // in C

// Create a new node
node* makenode(int x) {
    node* newnode = new node();
    newnode->data = x;
    newnode->next = nullptr;
    return newnode;
}

// Traverse the linked list and print the data in each node
void duyet(node* head) {
    node* tmp = head;
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Count the number of nodes in the linked list
int count(node* head) {
    int dem = 0;
    while (head != nullptr) {
        ++dem;
        head = head->next;
    }
    return dem;
}
int count1(node* head){
	if(head==NULL) return 0;
	else return 1+ count1(head->next);
}
// Add a new node at the front of the linked list
void pushfront(node** head, int x) {
    node* newnode = makenode(x);
    newnode->next = *head;
    *head = newnode;
}

// Add a new node at the end of the linked list
void pushback(node** head, int x) {
    node* newnode = makenode(x);
    node* tmp = *head;

    if (*head == nullptr) {
        *head = newnode;
        return;
    }

    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }

    tmp->next = newnode;
}

// Insert a new node at a specific position in the linked list
void pushat(node** head, int k, int x) {
    node* newnode = makenode(x);
    node* tmp = *head;

    if (*head == nullptr) {
        *head = newnode;
        return;
    }

    for (int i = 0; i < k; i++) {
        tmp = tmp->next;
    }

    newnode->next = tmp->next;
    tmp->next = newnode;
}

// Add a new element at the end of the linked list
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
}

// Remove a node with a specific value from the linked list
node* removelement(node* head, int val) {
    if (head == nullptr)
        return head;

    node* dummy = new node;
    dummy->next = head;
    node* prev = dummy;
    node* curr = head;

    while (curr != nullptr) {
        if (curr->data == val) {
            prev->next = curr->next;
            delete (curr);
            curr = curr->next;
        } else {
            prev = prev->next;
            curr = curr->next;
        }
    }

    return dummy->next;
}
//reverse dslk

void reverse(node *&head){
    node *current = head;
    node *prev = NULL;
    node *next = NULL;
    
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

int main() {
    node* head = nullptr;

    while (1) {
        cout << "---------------------" << endl;
        cout << "0. nhap vao mang" << endl;
        cout << "1. them vao dau" << endl;
        cout << "2. them vao cuoi" << endl;
        cout << "3. them vao giua" << endl;
        cout << "6. xoa phan tu " << endl;
        cout << "4. duyet" << endl;
        cout << "5. reverse dslk"<<endl;
        cout << "7. thoat" << endl;
        cout << "---------------------" << endl;
        cout << "nhap luu chon: ";

        int lc;
        cin >> lc;

        if (lc == 1) {
            int x;
            cout << "nhap x: ";
            cin >> x;
            pushfront(&head, x);
        } else if (lc == 2) {
            int x;
            cout << "nhap x: ";
            cin >> x;
            pushback(&head, x);
        } else if (lc == 3) {
            int x;
            cout << "nhap x: ";
            cin >> x;
            int k;
            cout << "nhap k: ";
            cin >> k;
            pushat(&head, k, x);
        } else if (lc == 4) {
            duyet(head);
        } else if (lc == 0) {
            int x;
            cout << "nhap so luong phan tu: ";
            cin >> x;
            int k;
            cout << "nhap gia tri cac phan tu: ";
            for (int i = 0; i < x; i++) {
                cin >> k;
                if (i == 0) {
                    head = makenode(k);
                } else {
                    addelement(head, k);
                }
            }
        } else if (lc == 6) {
            int val;
            cin >> val;
            head = removelement(head, val);
        } else if(lc==5){
        	reverse(head);
		}else {
            break;
        }
    }
    
    return 0;
}



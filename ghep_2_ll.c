#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* makeNode(int a) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = a;
    newnode->next = NULL;
    return newnode;
}

Node* addelement(Node* r, int a) {
    Node* newnode = makeNode(a);
    if (r == NULL) {
        r = newnode;
        return r;
    }
    Node* tmp = r;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newnode;
    return r;
}

// kt ll tang ko
bool kt_tang(Node* r) {
    Node* tmp = r;
    while (tmp != NULL && tmp->next != NULL) {
        if (tmp->data > tmp->next->data)
            return false;
        tmp = tmp->next;
    }
    return true;
}

void reverse(Node** head) {
    Node* current = *head;
    Node* prev = NULL;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// merge 2 ll khong tang -> giam
// 5 4 3 2 1
// 8 5 3 2
Node* dSort(Node* list1, Node* list2) {
    Node* dummy = makeNode(0); // Use a dummy node to simplify the code
    Node* tmp1 = list1;
    Node* tmp2 = list2;
    Node* current = dummy;

    while (tmp1 != NULL && tmp2 != NULL) {
        if (tmp1->data > tmp2->data) {
            current->next = makeNode(tmp1->data);
            tmp1 = tmp1->next;
        } else {
            current->next = makeNode(tmp2->data);
            tmp2 = tmp2->next;
        }
        current = current->next;
    }

    while (tmp1 != NULL) {
        current->next = makeNode(tmp1->data);
        tmp1 = tmp1->next;
        current = current->next;
    }

    while (tmp2 != NULL) {
        current->next = makeNode(tmp2->data);
        tmp2 = tmp2->next;
        current = current->next;
    }

    return dummy->next;
}

// merge 2 ll khong giam -> tang
Node* iSort(Node* list1, Node* list2) {
    Node* dummy = makeNode(0);
    Node* tmp1 = list1;
    Node* tmp2 = list2;
    Node* current = dummy;

    while (tmp1 != NULL && tmp2 != NULL) {
        if (tmp1->data > tmp2->data) {
            current->next = makeNode(tmp2->data);
            tmp2 = tmp2->next;
        } else {
            current->next = makeNode(tmp1->data);
            tmp1 = tmp1->next;
        }
        current = current->next;
    }

    while (tmp1 != NULL) {
        current->next = makeNode(tmp1->data);
        tmp1 = tmp1->next;
        current = current->next;
    }

    while (tmp2 != NULL) {
        current->next = makeNode(tmp2->data);
        tmp2 = tmp2->next;
        current = current->next;
    }

    return dummy->next;
}

void print(Node* r) {
    Node* tmp = r;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void freeNode(Node* r) {
    Node* tmp;
    while (r != NULL) {
        tmp = r;
        r = r->next;
        free(tmp);
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int y;
        scanf("%d", &y);
        list1 = addelement(list1, y);
    }
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int y;
        scanf("%d", &y);
        list2 = addelement(list2, y);
    }
    bool tang1 = kt_tang(list1);
    bool tang2 = kt_tang(list2);
    char sort[20];
    scanf("%s", sort);
    Node* dummy = NULL;
    if (tang1 == true && tang2==true) {
        if (strcmp(sort, "dSort") == 0) {
            dummy = iSort(list1, list2);
            reverse(&dummy);
        } else if (strcmp(sort, "iSort") == 0) {
            dummy = iSort(list1, list2);
        }
    } else if(tang1 == false && tang2 == false) {
        if (strcmp(sort, "dSort") == 0) {
            dummy = dSort(list1, list2);
        } else if (strcmp(sort, "iSort") == 0) {
            dummy = dSort(list1, list2);
            reverse(&dummy);
        }
    }else if(tang1 == true && tang2 == false){
        if (strcmp(sort, "dSort") == 0) {
            reverse(&list1);
            dummy=dSort(list1,list2);
        } else if (strcmp(sort, "iSort") == 0) {
            reverse(&list2);
            dummy=iSort(list1,list2);
        }
    }else if(tang1 == false && tang2 == true){
        if (strcmp(sort, "dSort") == 0) {
            reverse(&list2);
            dummy=dSort(list1,list2);
        } else if (strcmp(sort, "iSort") == 0) {
            reverse(&list1);
            dummy=iSort(list1,list2);
        }
    }
    print(dummy);
    freeNode(list1);
    freeNode(list2);
    freeNode(dummy);
    return 0;
}

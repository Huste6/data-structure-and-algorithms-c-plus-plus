#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Node {
    int a;
    int n;
    struct Node* next;
} Node;

struct Poly {
    Node* head;
    Node* tail;
};

void init(struct Poly* list) {
    list->head = list->tail = NULL;
}

Node* makeNode(int a, int n) {
    //if (a == 0 && n==0) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->a = a; newNode->n = n; newNode->next = NULL;
    return newNode;
}

void insert(struct Poly* list, Node* p) {
    if (list->head == NULL) {
        list->head = p;
        list->tail = p;
        return;
    }
    list->tail->next = p;
    list->tail = p;
}

void Sum_2_poly(struct Poly* list1, struct Poly* list2, struct Poly* list3) {
    Node* p1 = list1->head;
    Node* p2 = list2->head;
    while (p1 != NULL && p2 != NULL) {
        Node* p3 = makeNode(p1->a + p2->a, p1->n);
        insert(list3, p3);
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1 != NULL) {
        Node* p3 = makeNode(p1->a, p1->n);
        insert(list3, p3);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        Node* p3 = makeNode(p2->a, p2->n);
        insert(list3, p3);
        p2 = p2->next;
    }
}

void minus_2_poly(struct Poly* list1, struct Poly* list2, struct Poly* list3) {
    Node* p1 = list1->head;
    Node* p2 = list2->head;
    while (p1 != NULL && p2 != NULL) {
        Node* p3 = makeNode(p1->a - p2->a, p1->n);
        insert(list3, p3);
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1 != NULL) {
        Node* p3 = makeNode(p1->a, p1->n);
        insert(list3, p3);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        Node* p3 = makeNode(-p2->a, p2->n);
        insert(list3, p3);
        p2 = p2->next;
    }
}

int count(struct Poly* list) {
    int cnt = 0;
    Node* tmp = list->head;
    while (tmp != NULL) {
        if(tmp->a!=0) cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
int count1(struct Poly* list) {
    int cnt = 0;
    Node* tmp = list->head;
    while (tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
void print(struct Poly* list3) {
    printf("%d ", count(list3));
    Node* tmp = list3->head;
    while (tmp != NULL) {
        printf("%d ", tmp->a);
        tmp = tmp->next;
    }
}

void free_Node(struct Poly* list) {
    Node* tmp = list->head;
    while (tmp != NULL) {
        Node* tmp1 = tmp;
        tmp = tmp->next;
        free(tmp1);
    }
}

bool check(struct Poly* list) {
    int cnt0 = 0;
    Node* tmp = list->head;
    while (tmp != NULL) {
        if (tmp->a == 0) cnt0++;
        tmp = tmp->next;
    }
    return count1(list) != cnt0;
}

int main() {
    struct Poly list1, list2, list3;
    init(&list1);
    init(&list2);
    init(&list3);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Node* newnode = makeNode(x, i);
        insert(&list1, newnode);
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        Node* newnode = makeNode(x, i);
        insert(&list2, newnode);
    }

    char cmd[10];
    scanf("%s", cmd);
    if (strcmp(cmd, "plus") == 0) {
        Sum_2_poly(&list1, &list2, &list3);
    } else if (strcmp(cmd, "minus") == 0) {
        minus_2_poly(&list1, &list2, &list3);
    }
    if (!check(&list3)) {
        printf("1 0");
    } else {
        print(&list3);
    }
    free_Node(&list1);
    free_Node(&list2);
    free_Node(&list3);
    return 0;
}

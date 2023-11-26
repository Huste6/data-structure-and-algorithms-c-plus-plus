#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int stt;
    char so_tuyen[30];
    struct Node* next;
} Node;

Node* root;

Node* makeNode(int stt, char ten[]) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    p->stt = stt;
    strcpy(p->so_tuyen, ten);
    p->next = NULL;
    return p;
}

void addElement(Node** r, int stt, char ten[]) {
    if (*r == NULL) {
        *r = makeNode(stt, ten);
        return;
    }
    Node* tmp = *r;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    Node* tmp1 = makeNode(stt, ten);
    tmp->next = tmp1;
}

void print(Node* r) {
    Node* tmp = r;
    while (tmp != NULL) {
        printf("%d %s\n", tmp->stt, tmp->so_tuyen);
        tmp = tmp->next;
    }
}

void load(char* filename) {
    int data;
    char str[100];
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        perror("Error opening file");
        return;
    }
    root = NULL;
    while (fscanf(f, "%d %s\n", &data, str) != EOF) {
        addElement(&root, data, str);
    }
    fclose(f);
}

void pushFirst(int stt, char ten[]) {
    Node* newNode = makeNode(stt, ten);
    newNode->next = root;
    root = newNode;
}

void find(int s) {
    Node* tmp = root;
    while (tmp != NULL) {
        if (tmp->stt == s) {
            printf("%s\n", tmp->so_tuyen);
            return;
        }
        tmp = tmp->next;
    }
    printf("khong tim thay %d\n", s);
}

int count(Node* r) {
    int cnt = 0;
    Node* tmp = r;
    while (tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

int viTri(int s) {
    int vt = 0;
    Node* tmp = root;
    while (tmp != NULL && tmp->stt != s) {
        vt++;
        tmp = tmp->next;
    }
    if (tmp != NULL) return vt;
    else return -1;
}

void removeElement(int s) {
    int k = viTri(s);
    Node* tmp = root;
    if (k == 0) {
        Node* tmp1 = tmp;
        root = tmp->next;
        free(tmp1);
        return;
    }
    else if (k == count(root) - 1) {
        while (tmp->next->next != NULL) {
            tmp = tmp->next;
        }
        free(tmp->next);
        tmp->next = NULL;
    }
    else {
        for (int i = 0; i < k - 1; i++) {
            tmp = tmp->next;
        }
        Node* tmp1 = tmp->next;
        tmp->next = tmp1->next;
        free(tmp1);
    }
}

void store(char* filename) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        perror("Error opening file");
        return;
    }
    Node* tmp = root;
    while (tmp != NULL) {
        fprintf(f, "%d %s\n", tmp->stt, tmp->so_tuyen);
        tmp = tmp->next;
    }
    fclose(f);
}

void freeNode() {
    while (root != NULL) {
        Node* tmp = root;
        root = root->next;
        free(tmp);
    }
}

int main() {
    while (1) {
        int d;
        printf("Enter operation (0: Load, 1: Print, 2: Add, 3: Find, 4: Remove, 6: Store, other: Exit): ");
        scanf("%d", &d);
        if (d == 0) {
            printf("Enter filename: ");
            char filename[100];
            scanf("%s", filename);
            load(filename);
        }
        else if (d == 1) {
            print(root);
        }
        else if (d == 2) {
            int s1;
            char ten1[30];
            printf("Enter stt: ");
            scanf("%d", &s1);
            getchar();
            printf("Enter so_tuyen: ");
            fgets(ten1, sizeof(ten1), stdin);
            pushFirst(s1, ten1);
            print(root);
        }
        else if (d == 3) {
            int s2;
            printf("Enter stt to find: ");
            scanf("%d", &s2);
            find(s2);
        }
        else if (d == 4) {
            int s3;
            printf("Enter stt to remove: ");
            scanf("%d", &s3);
            removeElement(s3);
        }
        else if (d == 6) {
            printf("Enter filename to store: ");
            char filename[30];
            scanf("%s", filename);
            store(filename);
        }
        else {
            break;
        }
    }
    freeNode();
    return 0;
}

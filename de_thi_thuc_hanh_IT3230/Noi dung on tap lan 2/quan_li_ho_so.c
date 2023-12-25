#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_Len 100

typedef struct hoso {
    char name[3][Max_Len];
    char email[Max_Len];
} hoso;

hoso a[20];
hoso b[20];
int n;
void LoadFile(char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong the mo file!\n");
        exit(1);
    }

    char tmp[Max_Len];
    int k = 0;

    while (fgets(tmp, sizeof(tmp), f)) {
        tmp[strcspn(tmp, "\n")] = '\0'; // Remove newline character
        if (strcmp(tmp, "#") == 0)
            break;

        int i = 0;
        char *token = strtok(tmp, " ");
        while (token != NULL) {
            if (i < 3) {
                strcpy(a[k].name[i], token);
            } else {
                strcpy(a[k].email, token);
            }
            token = strtok(NULL, " ");
            i++;
        }
        k++;
    }

    fclose(f);
}

void print(int n) {
    for (int i = 0; i < n; i++) {
        printf("Ten: %s %s %s email: %s\n", a[i].name[0], a[i].name[1], a[i].name[2], a[i].email);
    }
}

int cmp(hoso *a, hoso *b) {
    if (strcmp(a->name[2], b->name[2]) > 0)
        return 1;
    if (strcmp(a->name[2], b->name[2]) < 0)
        return 0;
    if (strcmp(a->name[1], b->name[1]) > 0)
        return 1;
    if (strcmp(a->name[1], b->name[1]) < 0)
        return 0;
    if (strcmp(a->name[0], b->name[0]) > 0)
        return 1;
    if (strcmp(a->name[0], b->name[0]) < 0)
        return 0;
    if (strcmp(a->email, b->email) > 0)
        return 1;
    if (strcmp(a->email, b->email) < 0)
        return 0;

    return 0;
}

void merge(int l, int m, int r) {
    int i = l, j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        if (cmp(&a[i], &a[j]) <= 0) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= m) {
        b[k++] = a[i++];
    }

    while (j <= r) {
        b[k++] = a[j++];
    }

    for (k = l; k <= r; k++) {
        a[k] = b[k];
    }
}

void mergesort(int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}

int binarysearch(int l, int r, char *name_sv) {
    if (l > r)
        return -1;
    char full_name1[Max_Len * 3];
    sprintf(full_name1, "%s %s %s", a[l].name[0], a[l].name[1], a[l].name[2]);
    int cmp_result1 = strcmp(full_name1, name_sv);
    if(cmp_result1==0) return l;
    int m = (l + r) / 2;
    char full_name[Max_Len * 3];
    sprintf(full_name, "%s %s %s", a[m].name[0], a[m].name[1], a[m].name[2]);
    int cmp_result = strcmp(full_name, name_sv);
    if (cmp_result == 0) {
        return m;
    } else if (cmp_result < 0) {
        return binarysearch(m + 1, r, name_sv);
    } else {
        return binarysearch(l, m - 1, name_sv);
    }
}

void insert(char *name, char *email, int *n) {
    int i = *n - 1;

    while (i >= 0) {
        char full_name[Max_Len * 3];
        sprintf(full_name, "%s %s %s", a[i].name[0], a[i].name[1], a[i].name[2]);
        int cmp_result = strcmp(full_name, name);
        if (cmp_result == 0) {
            printf("Ten %s da ton tai trong ho so!\n", name);
            return;
        } else if (cmp_result > 0) {
            a[i + 1] = a[i];
            i--;
        } else {
            break;
        }
    }
    i++;
    char *token = strtok(name, " ");
    int j = 0;

    while (token != NULL) {
        if (j == 0) {
            strcpy(a[i].name[0], token);
        } else if (j == 1) {
            strcpy(a[i].name[1], token);
        } else if (j == 2) {
            strcpy(a[i].name[2], token);
        }
        token = strtok(NULL, " ");
        j++;
    }
    strcpy(a[i].email, email);
    (*n)++;
}
void remove1(int index)
{
    for(int i=0;i<index;i++){
        b[i]=a[i];
    }
    for(int i=index+1;i<n;i++){
        b[i-1]=a[i];
    }
    for(int i=0;i<n-1;i++){
        a[i]=b[i];
    }
    n--;
}
void store(char *filename,int n)
{
    FILE*f=fopen(filename,"w");
    for(int i=0;i<n;i++){
        fprintf(f,"%s %s %s %s\n",a[i].name[0],a[i].name[1],a[i].name[2],a[i].email);
    }
    fprintf(f,"#\n");
    fclose(f);
}
int main() {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();
    LoadFile("quan_li_ho_so.txt");
    while (1) {
        printf("-------------------\n");
        printf("1.Merge sort\n");
        printf("2.Print\n");
        printf("3.Find\n");
        printf("4.Insert\n");
        printf("5.Remove\n");
        printf("6.Store\n");
        printf("-------------------\n");
        int cmd;
        printf("Nhap lenh: ");
        scanf("%d", &cmd);
        getchar();

        if (cmd == 1) {
            mergesort(0, n - 1);
            printf("Da sap xep thanh cong!\n");
        } else if (cmd == 2) {
            print(n);
        } else if (cmd == 3) {
            printf("Nhap ten sinh vien can tim kiem: ");
            char namesv[Max_Len];
            fgets(namesv, sizeof(namesv), stdin);
            namesv[strcspn(namesv, "\n")] = '\0';

            int k = binarysearch(0, n - 1, namesv);
            if (k == -1) {
                printf("Khong tim thay sinh vien!\n");
            } else {
                printf("Tim thay sinh vien %d: %s co email: %s\n", k , namesv, a[k].email);
            }
        } else if (cmd == 4) {
            printf("Nhap ten sinh vien can chen: ");
            char name[Max_Len];
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Nhap email sinh vien can chen: ");
            char email[Max_Len];
            scanf("%s",email);
            getchar();
            insert(name, email, &n);
        } else if(cmd==5){
            printf("Nhap ten sinh vien muon xoa: ");
            char name[Max_Len];
            fgets(name,sizeof(name),stdin);
            name[strcspn(name, "\n")] = '\0';
            int k = binarysearch(0, n - 1, name);
            if (k==-1){
                printf("Khong tim thay ten!\n");
            }else{
                remove1(k);
                print(n);
            }
        }else if(cmd==6){
            printf("Nhap filename muon luu: ");
            char filename[30];
            scanf("%s",filename);
            getchar();
            store(filename,n);
        }else{
            break;
        }
    }
    return 0;
}

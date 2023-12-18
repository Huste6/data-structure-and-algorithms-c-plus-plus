#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct HSSV {
    char Ho[30];
    char dem[30];
    char ten[30];
    char ngaysinh[30];
} HSSV;
HSSV a[10],tmp[10];
void xu_ly_file1(char *filename) {
    FILE *f = fopen(filename, "r");
    if(f==NULL){
        printf("khong the mo file!");return;
    }
    char tmp[100];
    int i = 0;
    while (fgets(tmp, sizeof(tmp), f)) {
        if (strcmp(tmp, "#") == 0) {
            break;
        }
        tmp[strlen(tmp) - 1] = '\0';
        if (i % 2 ==0) {
            int k = 0;
            char *token = strtok(tmp, " ");
            while (token != NULL) {
                if (k == 0) {
                    strcpy(a[i/2].Ho, token);
                } else if (k == 1) {
                    strcpy(a[i/2].dem, token);
                } else if (k == 2) {
                    strcpy(a[i/2].ten, token);
                }
                token = strtok(NULL, " ");
                k++;
            }
        } else {
            strcpy(a[i/2].ngaysinh, tmp);
        }

        i++;
    }
    fclose(f);
}

void xu_ly_file2(char *filename, int n) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong the mo file!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fscanf(f, "%s %s %s\n%s", a[i].Ho, a[i].dem, a[i].ten, a[i].ngaysinh);
    }

    fclose(f);
}

int cmp(HSSV *a, HSSV *b) {
    if (strcmp(a->ten, b->ten) > 0)
        return 1;
    if (strcmp(a->ten, b->ten) < 0)
        return 0;
    if (strcmp(a->dem, b->dem) > 0)
        return 1;
    if (strcmp(a->dem, b->dem) < 0)
        return 0;
    if (strcmp(a->Ho, b->Ho) > 0)
        return 1;
    if (strcmp(a->Ho, b->Ho) < 0)
        return 0;
    if (strcmp(a->ngaysinh, b->ngaysinh) > 0)
        return 1;
    if (strcmp(a->ngaysinh, b->ngaysinh) < 0)
        return 0;
    return 1;
}

void mergesort(int L, int M, int R) {
    int i = L, j = M + 1;
    for (int k = L; k <= R; k++) {
        if (i > M) {
            tmp[k] = a[j++];
        } else if (j > R) {
            tmp[k] = a[i++];
        } else {
            if (cmp(&a[j], &a[i])) {
                tmp[k] = a[i++];
            } else {
                tmp[k] = a[j++];
            }
        }
    }
    for (int k = L; k <= R; k++)
        a[k] = tmp[k];
}

void merge(int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge(l, m);
        merge(m + 1, r);
        mergesort(l, m, r);
    }
}

void print(int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %s %s co ngay sinh %s\n", a[i].Ho, a[i].dem, a[i].ten, a[i].ngaysinh);
    }
}

int partition(int l,int r)
{
    HSSV pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(cmp(&a[j],&pivot)==0){
            i++;
            HSSV tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
    }
    HSSV tmp=a[i+1];
    a[i+1]=a[r];
    a[r]=tmp;
    return i+1;
}
void quicksort(int l,int r)
{
    if(l<r){
        int index=(l+r)/2;
        index=partition(l,r);
        if(l<index){
            quicksort(l,index-1);
        }
        if(index<r){
            quicksort(index+1,r);
        }
    }
}
void heapify(int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && cmp(&a[l], &a[largest]) > 0) {
        largest = l;
    }

    if (r < n && cmp(&a[r], &a[largest]) > 0) {
        largest = r;
    }

    if (largest != i) {
        HSSV tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        heapify(n, largest);
    }
}

void heapSort(int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        HSSV tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        heapify(i, 0);
    }
}

int main() {
    clock_t start_t,end_t;
    int n;
    scanf("%d", &n);
    xu_ly_file2("profile.txt", n);
    while(1){
        printf("---------------------\n");
        printf("1.merge sort\n");
        printf("2.quick sort\n");
        printf("3.heap sort\n");
        printf("4.thoi gian chay cua 3 thuat toan tren\n");
        printf("---------------------\n");
        int cmd;scanf("%d",&cmd);
        if(cmd==1){
            merge(0,n-1);
            print(n);
        }else if(cmd==2){
            quicksort(0,n-1);
            print(n);
        }else if(cmd==3){
            heapSort(n);
            print(n);
        }else if(cmd==4){
            xu_ly_file2("profile.txt", n);
            start_t=clock();
            merge(0,n-1);
            end_t=clock();
            double total_t=((double)(end_t-start_t))/CLOCKS_PER_SEC;
            printf("Thoi gian chay bang merge sort: %f\n",total_t);

            xu_ly_file2("profile.txt", n);
            start_t=clock();
            quicksort(0,n-1);
            end_t=clock();
            total_t=((double)(end_t-start_t))/CLOCKS_PER_SEC;
            printf("Thoi gian chay bang quick sort: %f\n",total_t);

            xu_ly_file2("profile.txt", n);
            start_t=clock();
            heapSort(n);
            end_t=clock();
            total_t=((double)(end_t-start_t))/CLOCKS_PER_SEC;
            printf("Thoi gian chay bang heap sort: %f\n",total_t);

        }else break;
    }
    return 0;
}

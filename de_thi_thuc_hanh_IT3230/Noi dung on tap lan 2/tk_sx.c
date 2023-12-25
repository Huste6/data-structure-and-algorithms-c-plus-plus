#include<stdio.h>
#include<stdlib.h>
#define Max_Len 20
int a[Max_Len];int b[Max_Len];int n;
void selectionSort(int n)
{
    for(int k=0;k<n;k++){
        int min=k;
        for(int j=k+1;j<n;j++){
            if(a[min]>a[j]) min=j;
        }
        int tmp=a[min];
        a[min]=a[k];
        a[k]=tmp;
    }
}
void insertionSort(int n)
{
    for(int k=0;k<n;k++){
        int last=a[k];
        int j=k;
        while(j>1 && a[j-1]>last){
            a[j]=a[j-1];
            j--;
        }
        a[j]=last;
    }
}
void bubleSort(int n)
{
    int swapped;
    do{
        swapped=0;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                int tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
                swapped=1;
            }
        }
    }while(swapped==1);
}
void merge(int l,int m,int r)
{
    int i=l,j=m+1;
    for(int k=l;k<=r;k++){
        if(i>m){
            b[k]=a[j++];
        }else if(j>r) b[k]=a[i++];
        else{
            if(a[i]>a[j]){
                b[k]=a[j++];
            }else{
                b[k]=a[i++];
            }
        }
    }
    for(int k=l;k<=r;k++) a[k]=b[k];
}
void mergesort(int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(l,m);
        mergesort(m+1,r);
        merge(l,m,r);
    }
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int l, int r)
{
    int pivot1 = a[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (a[j] < pivot1)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return (i + 1);
}

void quickSort(int l, int r)
{
    if (l < r)
    {
        int p = partition(l, r);
        quickSort(l, p - 1);
        quickSort(p + 1, r);
    }
}
void heapify(int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(n, largest);
    }
}

void heapSort(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(i, 0);
    }
}
void print()
{
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
void xulyfile(char*filename)
{
    FILE*f=fopen(filename,"r");
    if(f==NULL){
        printf("Not Found!\n");
        return;
    }
    fscanf(f,"%d\n",&n);
    for(int i=0;i<n;i++){
        fscanf(f,"%d ",&a[i]);
    }
    fclose(f);
}
int binarysearch(int l,int r,int y)
{
    if(l>r) return -1;
    if(l==r){
        if(a[l]=y) return l;
        else return -1;
    }
    int m=(l+r)/2;
    if(a[m]==y) return m;
    else if(a[m]>y) return binarysearch(l,m-1,y);
    else return binarysearch(m+1,r,y);
}
void binarysearchSolve(int y)
{
    int c[n];
    for(int i=0;i<n;i++) c[i]=0;
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(c[i]!=-1){
            int ok=binarysearch(i+1,n-1,y-a[i]);
            if(ok!=-1){
                cnt++;
                printf("cap (%d:%d)\n",a[i],a[ok]);
            }
            c[i]=-1;c[ok]=-1;
        }
    }
    printf("Co %d cap co tong bang %d\n",cnt,y);
}
int main()
{
    while(1){
        printf("-------------\n");
        printf("1.selection sort\n");
        printf("2.insertion sort\n");
        printf("3.buble sort\n");
        printf("4.merge sort\n");
        printf("5.quick sort\n");
        printf("6.heap sort\n");
        printf("7.Tim kiem nhi phan\n");
        printf("8.Tim so cap bang tong cho truoc\n");
        printf("-------------\n");
        int cmd;scanf("%d",&cmd);
        getchar();
        if(cmd==1){
            xulyfile("test_case.txt");
            selectionSort(n);
            print();
            printf("\n");
        }else if(cmd==2){
            xulyfile("test_case.txt");
            insertionSort(n);
            print();
            printf("\n");
        }else if(cmd==3){
            xulyfile("test_case.txt");
            bubleSort(n);
            print();
            printf("\n");
        }else if(cmd==4){
            xulyfile("test_case.txt");
            mergesort(0,n-1);
            print();
            printf("\n");
        }else if(cmd==5){
            xulyfile("test_case.txt");
            quickSort(0,n-1);
            print();
            printf("\n");
        }else if(cmd==6){
            xulyfile("test_case.txt");
            heapSort(n);
            print();
            printf("\n");
        }else if(cmd==7){
            int tmp;scanf("%d",&tmp);
            int k=binarysearch(0,n-1,tmp);
            if(k==-1) printf("Not found\n");
            else printf("found tai chi so %d\n",k);
        }else if(cmd==8){
            int tmp;scanf("%d",&tmp);
            binarysearchSolve(tmp);
        }
        else break;
    }
    return 0;
}

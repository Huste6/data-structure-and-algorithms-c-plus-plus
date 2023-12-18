#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max_Len 1000001
int a[Max_Len];
int sz,Q;
void truc_tiep()
{
    int cnt=0;
    for(int i=0;i<sz-1;i++){
        for(int j=i+1;j<sz;j++){
            if(a[i]+a[j]==Q){
                cnt++;
            }
        }
    }
    printf("result= %d",cnt);
}
int binarysearch(int l,int r)
{
    if(l>r) return 0;
    if(l==r)
    {
        if(a[l]+a[r]==Q) return 1;
        else return 0;
    }
    int m=(l+r)/2;
    if(a[m]==Q) return 1;
    else if(a[m]>Q) return binarysearch(l,m-1);
    else return binarysearch(m+1,r);
}
int random(int minN,int maxN)
{
    return minN+rand()%(maxN+1-minN);
}
void sinh_ngau_nhien(int minN,int maxN)
{
    srand((int)time(0));
    for(int i=0;i<sz;i++){
        a[i]=random(minN,maxN);
    }
}
int main()
{
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d%d",&sz,&Q);
    //int minN,maxN;
    //scanf("%d%d",&minN,&maxN);
    //sinh_ngau_nhien(minN,maxN);
    printf("result=%d",binarysearch(0,sz-1));
}

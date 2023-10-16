#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int x[MAX],n;
int cot[MAX],d1[MAX],d2[MAX];
void print(){
    for(int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void try1(int i){
    for(int j=1;j<=n;j++){
        if(cot[j]==1 && d1[i-j+n]==1 && d2[i+j-1]==1){
            x[i]=j;
			cot[j]=d1[i-j+n]=d2[i+j-1]=0;
            if(i==n) print();
            else try1(i+1);
            //backtrack
            cot[j]=d1[i-j+n]=d2[i+j-1]=1;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=99;i++){
        cot[i]=d1[i]=d2[i]=1;
    }
    try1(1);
    return 0;
}

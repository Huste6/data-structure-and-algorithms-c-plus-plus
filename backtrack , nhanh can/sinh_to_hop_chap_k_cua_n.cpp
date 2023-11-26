#include<bits/stdc++.h>
using namespace std;
#define MAX 100l
int x[MAX],n,k;

void print(){
	for(int i=1;i<=k;i++){
		cout<<x[i];
	}
	cout<<endl;
}
void try1(int i){
	for(int j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if(i==k) print();
		else try1(i+1);
	}
}
int main(){
	cin>>k>>n;
	try1(1);
}

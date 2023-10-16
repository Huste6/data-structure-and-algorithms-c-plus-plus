#include<bits/stdc++.h>
using namespace std;
#define MAX_LEN 20
int n,k;
int x[MAX_LEN];
void print(){
	for(int i=1;i<=k;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
bool check(int x[]){
	for(int i=1;i<=k;i++){
		if(x[i]+1==x[i+1]) return false;
	}
	return true;
}
void try1(int i){
	if(i>k){
		if(check(x)){
			print();
		}
		return;
	}
	for(int j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		try1(i+1);
	}
}
int main(){
	cin>>n>>k;
	try1(1);
	return 0;
}

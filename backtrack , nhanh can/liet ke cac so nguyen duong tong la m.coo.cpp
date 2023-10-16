#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int n,x[MAX],sum,M;
void print(){
	for(int i=1;i<=n;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
void try1(int k){
	for(int i=1;i<=M-sum-(n-k);i++){
		if(i+sum<=M){
			sum+=i;
			x[k]=i;
			if(k==n && sum==M) print();
			else try1(k+1);
			sum-=i;
		}
	}
}
int main(){
	cin>>n>>M;
	try1(1);
}

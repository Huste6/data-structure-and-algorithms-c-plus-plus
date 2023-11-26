#include<bits/stdc++.h>
using namespace std;
#define MAX 100l
bool used[MAX]={false};
int x[MAX],n;
void print(){
	for(int i=1;i<=n;i++){
		cout<<x[i];
	}
	cout<<endl;
}
void try1(int i){
	for(int j=1;j<=n;j++){
		if(!used[j]){
			x[i]=j;
			used[j]=true;

			if(i==n) print();
			else try1(i+1);
			used[j]=false;
		}
	}
}
int main(){
	cin>>n;
	try1(1);
}

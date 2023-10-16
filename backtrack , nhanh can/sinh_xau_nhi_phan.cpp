#include<bits/stdc++.h>
using namespace std;
#define MAX 100l
int x[MAX],n;
void print(){
	for(int i=1;i<=n;i++){
		cout<<x[i];
	}
	cout<<endl;
}
void try1(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n) print();
		else try1(i+1);
	}
}
//2 bit lien tiep khong chua 1
void try2(int i){
	for(int j=0;j<=1;j++){
		if(j+x[i-1]<2){
			x[i]=j;
			if(i==n) print();
			else try2(i+1);
		}
	}
}
int main()
{
	cin>>n;
	try2(1);
}

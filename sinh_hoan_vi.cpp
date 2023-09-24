#include<bits/stdc++.h>
using namespace std;
int n,ok,a[100];
void ktao(){
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
}
void sinh(){
	int i=n-1;
	while(i>=1 && a[i]>a[i+1]){
		--i;
	}
	if(i==0){
		ok=0;//cau hinh cuoi cung
	}else{
		//di tim thg >a[i] trong doan [i+1,n]
		int j=n;
		while(a[i]>a[j]) --j;
		swap(a[i],a[j]);
		int l=i+1,r=n;
		while(l<r){
			swap(a[l],a[r]);
			++l;--r;
		}
		//reverse(a+i+1,a+n+1);
	}
}/*
int main(){
	cin>>n;
	ok=1;
	ktao();
	while(ok){
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
		cout<<endl;
		sinh();
	}
}*/
/*
int main(){
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	do{
		for(int i=0;i<n;i++){
			cout<<a[i];
		}
		cout<<endl;
	}while(next_permutation(a,a+n));
	return 0;
}*/
int main(){
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		a[i]=n-i;
	}
	do{
		for(int i=0;i<n;i++){
			cout<<a[i];
		}
		cout<<endl;
	}while(prev_permutation(a,a+n));
	return 0;
}

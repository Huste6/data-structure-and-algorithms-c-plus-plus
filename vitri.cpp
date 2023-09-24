#include<bits/stdc++.h>
using namespace std;
bool bs(int a[],int n,int x){
	int l=0,r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x) return true;
		else if(a[m]<x) l=m+1;
		else r=m-1;
	}
	return false;
}
int dautien(int a[],int n,int x){
	int res=-1,l=0,r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			res=m+1;
			r=m-1;//tim them o ben trai
		}else if(a[m]<x) l=m+1;
		else r=m-1;
	}
	return res;
}
int cuoicung(int a[],int n,int x){
	int res=-1,l=0,r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			res=m+1;
			l=m+1;//tim them o ben phai
		}else if(a[m]<x) l=m+1;
		else r=m-1; 
	}
	return res;
}
int main(){
	int n,x;cin>>n>>x;
	int a[n];
	for(int &x:a) cin>>x;
	cout<<dautien(a,n,x)<<" "<<cuoicung(a,n,x)<<endl;
}

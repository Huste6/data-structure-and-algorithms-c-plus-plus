#include<bits/stdc++.h>
using namespace std;
int merge(int a[],int l,int m,int r){
	vector<int> x(a+l,a+m+1);
	vector<int> y(a+m+1,a+r+1);
	int i=0,j=0,cnt=0;
	while(i<x.size()&&j<y.size()){
		if(x[i]<=y[j]){
			a[l]=x[i];++l;++i;
		}else{
			//neu x[i] > y[j] thi moi phan tu sau chi so i deu thoa man
			cnt+=x.size()-i;
			a[l]=y[j];++l;++j;
		}
	}
	while(i<x.size()){
		a[l]=x[i];++l;++i;
	}
	while(j<y.size()){
		a[l]=y[j];++l;++j;
	}
	return cnt;
}
int mergesort(int a[],int l,int r){
	int dem=0;
	if(l<r){
		int m=(l+r)/2;
		dem+=mergesort(a,l,m);//so luong cap nghich the trong mang trai
		dem+=mergesort(a,m+1,r);//so luong cap nghich the trong mang phai
		dem+=merge(a,l,m,r);//so luong cap nghich the sau tron
	}
	return dem;
}
int main(){
	int n;cin>n;
	int a[n];
	for(int &x:a) cin>>x;
	cout<<mergesort(a,0,n-1)<<endl;
}

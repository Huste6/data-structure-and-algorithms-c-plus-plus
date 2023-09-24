#include<bits/stdc++.h>
using namespace std;
//tim 2 chi so co gia tri tong bang k cho truoc trong mang duoc sap xep
void tk(int a[],int n,int k){
	int i=1;i=n;
	while(i<j){
		if(a[i]+a[j]==k){
			cout<<i<<" "<<j;
			return 0;
		}
		if(a[i]+a[j]<x){
			i+=1;
		}else{
			j-=1;
		}
	}
}
//tim do dai doan con dai nhat trong day sao cho tong cac phan tu khong qua s
void tk1(int a[],int n,int s){
	int ans=0,sum=0;
	for(int l=1;r=1;r<=n;r++){
		sum+=a[r];
		while(sum>s){
			sum-=a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}

int main(){
	
}

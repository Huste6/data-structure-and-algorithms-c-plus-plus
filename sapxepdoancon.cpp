// 1 2 3 '5' 3  6 '4' 6 7 8 10
// (0->n) if(a[i]>a[i+1])->l=i;
// (n->0) if(a[i]<a[i-1])->r=i;
// sap xep lai doan con
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n];
		for(int &x:a) cin>>x;
		int l,r;
		for(int i=0;i<n;i++){
			if(a[i]>a[i+1]){
				l=i;break;
			}
		}
		for(int i=n-1;i>0;i++){
			if(a[i]<a[i-1]){
				r=i;break;
			}
		}
		int min=*min_element(a+l,a+r+1);
		int max=*max_element(a+l,a+r+1);
		for(int i=0;i<=l;i++){
			if(a[i]>min){
				l=i;break;
			}
		}
		for(int i=n-1;i>=r;i++){
			if(a[i]<max){
				r=i;break;
			}
		}
		cout<<l+1<<" "<<r+1;
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	int a[n];
	for(int &x:a) cin>>x;
	long long sum=0;
	int l=0,r;
	long long ans=0;
	for(r=0;r<n;r++){
		sum+=a[r];
		while(sum>k){
			sum-=a[l];++l;
		}
		ans+=r-l+1;
	}
	cout<<ans;
}

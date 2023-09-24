#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,s;cin>>n>>s;
	int a[n];
	for(int &x:a) cin>>x;
	long long sum=0;
	int l=0,r,ans=1e9;
	for(r=0;r<n;r++){
		sum+=a[r];
		while(sum>=s){
			ans=min(ans,r-l+1);
			sum-=a[l];++l;
		}
	}
	if(ans==1e9) cout<<"-1\n";
	else cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	int a[n],b[m];
	for(int &x:a) cin>>x;
	for(int &x:b) cin>>x;
	int i=0,j=0;
	long long ans=0;
	while(i<n && j<m){
		if(a[i]<b[j]){
			++i;continue;
		}else if(a[i]>b[j]){
			++j;continue;
		}
		int cnt=0,cnt1=0;
		while(a[i]==b[j]){
			++cnt;++i;
		}
		--i;
		while(a[i]==b[j]){
			++cnt1;++j;
		}
		ans+=1ll*cnt*cnt1;
	}
	cout<<ans;
	return 0;
}

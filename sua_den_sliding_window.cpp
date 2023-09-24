#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,b;
	//k la so den lien tiep can sang
	//b la so den bi hong
	cin>>n>>k>>b;
	int a[n]={0};
	for(int i=0;i<b;i++){
		int x;cin>>x;
		a[x]=1;//den bi hong danh so la 1
	}
	int cnt=0;
	for(int i=0;i<k;i++){
		if(a[i]==0) cnt++;
	}
	int ans=0;
	for(int i=k;i<n;i++){
		if(a[i-k]==0) --cnt;
		if(a[i]==0) ++cnt;
		ans=max(ans,cnt);
	}
	cout<<k-ans;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	int a[n];
	for(int &x:a) cin>>x;
	int dem[100000]={0};
	int cnt=0;//dem so luong khac nhau
	long long ans=0;
	int l=0;
	for(int r=0;r<n;r++){
		dem[a[r]]++;
		if(dem[a[r]]==1) cnt++;
		//2 2 2 4 3 2 3
		while(cnt>k){
			if(dem[a[l]]==1) --cnt;
			dem[a[l]]--;
			++l;
		}
		//cnt<=k
		ans+=r-l+1;
	}
	cout<<ans;
}

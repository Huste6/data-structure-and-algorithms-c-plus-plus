#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s;cin>>n>>s;
	int w[n+1],v[n+1];
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++) cin>>v[i];
	int dp[n+1][s+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			//khong chon do vat thu i
			dp[i][j]=dp[i-1][j];
			//co the dua do vat thu i vao
			if(j>=w[i]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
			}
		}
	}
	cout<<dp[n][s];
}

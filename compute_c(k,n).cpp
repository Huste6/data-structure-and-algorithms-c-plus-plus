#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
int c(int k, int n) {
    int dp[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
    }
    return dp[n][k];
}
int main(){
	int k,n;cin>>k>>n;
	cout<<c(k,n);
}

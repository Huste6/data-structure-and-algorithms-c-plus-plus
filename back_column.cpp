#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int cnt=0,cnt1=0;
	for(int i=0;i<m;i++){
		vector<int> s;
		for(int j=0;j<n;j++){
			if(a[j][i]==1) s.push_back(a[j][i]);
		}
		if(s.size() == n) cnt++;
	}
	cout<<cnt;
}

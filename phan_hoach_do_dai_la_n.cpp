#include<bits/stdc++.h>
using namespace std;
void solve(int n,int m,vector<int>& v){
	if(n==1){
		v.push_back(m);
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		v.pop_back();
		return;
	}
	for(int i=1;i<=m-n+1;i++){
		v.push_back(i);
		solve(n-1,m-i,v);
		v.pop_back();
	}
}
int main(){
	vector<int> v;
	int n,m;cin>>n>>m;
	solve(n,m,v);
	return 0;
}

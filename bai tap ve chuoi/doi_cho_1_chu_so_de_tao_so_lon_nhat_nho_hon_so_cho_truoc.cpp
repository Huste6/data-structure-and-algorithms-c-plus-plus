#include<bits/stdc++.h>
using namespace std;
//thuat toan sinh ke tiep
void solve(){
	string s;cin>>s;
	int i=s.length()-2;
	while(i>=0&&s[i]<=s[i+1]){
		--i;
	}
	if(i==-1){
		cout<<"-1\n";return;
	}
	int j=s.length()-1;
	while(s[i] <= s[j] || (s[j-1]==s[j] &&s[j] < s[i])){
		--j;
	}
	swap(s[i],s[j]);
	if(s[0]=='0') cout<<"-1\n";
	else cout<<s<<endl;
}
int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;cin>>s;
	int a[26]={0};
	for(char x:s) a[x-'a']++;
	int max_val = *max_element(a,a+26);
	if(s.length() - max_val >= max_val-1) cout<<"yes";
	else cout<<"no";
}
int main(){
	solve();
	return 0;
}

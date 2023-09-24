#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);
		map<char,int> mp;
		for(char x:s){
			mp[x]++;
		}
		for(auto it:s){
			if(mp[it]==1){
				cout<<it;
			}
		}
		cout<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	unordered_set<char> se;
	for(int i=0;i<s.length();i++){
		if(se.find(s[i])!=se.end()){
			se.erase(s[i]);
		}else{
			se.insert(s[i]);
		}
	}
	for(char x:se){
		if(se.find(x)!=se.end()){
			cout<<x<<endl;
			break;
		}
	}
}

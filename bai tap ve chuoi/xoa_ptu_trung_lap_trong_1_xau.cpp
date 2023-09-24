#include<bits/stdc++.h>
using namespace std;
string xoaphantutrung(string s){
	int i=0,j=0;
	int n=s.size();
	while(j<n){
		if(s[i]!=s[j]){
			i++;
			s[i]=s[j];
		}
		j++;
	}
	return s.substr(0,i+1);
}
int main(){
	string s;cin>>s;
	cout<<xoaphantutrung(s);
}

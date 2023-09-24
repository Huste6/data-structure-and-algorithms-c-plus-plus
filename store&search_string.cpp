#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	vector<string> v;
	while(cin>>s){
		if(s=="*") break;
		else v.push_back(s);
	}
	string s1,s2;
	while(cin>>s1){
		if(s1=="find"){
			cin>>s2;
			if(find(v.begin(), v.end(), s2) != v.end()){
				cout<<"1\n";
			}else{
				cout<<"0\n";
			}
		}else if(s1=="insert"){
			cin>>s2;
			if(find(v.begin(), v.end(), s2) != v.end()){
				cout<<"0\n";
			}else{
				cout<<"1\n";
				v.push_back(s2);
			}
		}else if(s=="***"){
			break;
		}
	}
	
}

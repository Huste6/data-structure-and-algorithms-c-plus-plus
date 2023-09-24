#include<bits/stdc++.h>
using namespace std;
/*
int main(){
	int t;cin>>t;
	cin.ignore();
	while(t--){
		string s; getline(cin,s);
		vector<string> v;
		for(int i=0;i<s.length();i++){
			s[i]=tolower(s[i]);
		}
		stringstream ss(s);
		string tmp;
		while(ss>>tmp){
			v.push_back(tmp);
		}
		cout<<v[v.size()-1];
		for(int i=0;i<v.size()-1;i++){
			cout<<v[i][0];
		}
		cout<<"@gmail.com"<<endl;
	}
}*/
//neu email bi trung 
int main(){
	int t;cin>>t;
	cin.ignore();
	map<string,int> mp;
	while(t--){
		string s;getline(cin,s);
		for(int i=0;i<s.length();i++){
			s[i]=tolower(s[i]);
		}
		string tmp;
		vector<string> v;
		stringstream ss(s);
		string res="";
		while(ss>>tmp){
			v.push_back(tmp);
		}
		res+=v[v.size()-1];
		for(int i=0;i<v.size();i++){
			res+=v[i][0];
		}
		if(mp[res]==0){
			cout<<res<<"@gmail.com"<<endl;
		}else{
			cout<<res<<mp[res]+1<<"@gmail.com"<<endl;
		}
		mp[res]++;
	}
}

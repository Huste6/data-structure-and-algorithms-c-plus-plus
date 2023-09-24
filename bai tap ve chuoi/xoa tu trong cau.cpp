#include<bits/stdc++.h>
using namespace std;
//python    java     php c++

int main(){
	string s;
	getline(cin,s);
	stringstream ss(s);
	string word;int cnt=0;
	vector<string> v;
	string s1;cin>>s1;
	while(ss>>word){
		//++cnt;
		//cout<<word<<" ";
		if(word!=s1){
			v.push_back(word);
		}
	}	
	//cout<<endl;
	//cout<<cnt<<endl;
	for(string x:v){
		cout<<x<<" ";
		if(i!=v.size()-1){
			cout<<" ";
		}
	}
	return 0;
}

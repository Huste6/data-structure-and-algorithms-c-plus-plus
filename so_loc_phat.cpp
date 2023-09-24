#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<string> res;
ll ans[101];
void init(){
	queue<string> q;
	q.push("6");
	q.push("8");
	res.push_back("6");
	res.push_back("8");
	while(true){
		string top=q.front();
		q.pop();
		if(top.length()==15) break;
		res.push_back(top+"6");
		res.push_back(top+"8");
		q.push(top+"6");
		q.push(top+"8");
	}
}
int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		vector<string> tmp;
		for(string s:res){
			if(s.length() == n+1) break;
			tmp.push_back(s);
		}
		reverse(tmp.begin(),tmp.end());
		for(string s:tmp){
			cout<<s<<" ";
		}
		cout<<endl;
	}
}

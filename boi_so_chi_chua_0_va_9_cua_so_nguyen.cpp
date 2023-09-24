#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> res;
ll ans[101];
void init(){
	queue<string> q;
	q.push("9");
	res.push_back(9);
	while(1){
		string top=q.front();
		q.pop();
		if(top.size()==12) break;
		res.push_back(stoll(top+"0"));
		res.push_back(stoll(top+"9"));
		q.push(top+"0");
		q.push(top+"9");
	}
	for(int i=1;i<=100;i++){
		for(ll x:res){
			if(x%i==0){
				ans[i]=x;
				break;
			}
		}
	}
}
int main(){
	init();
	for(int i=1;i<=100;i++){
		cout<<i<<" "<<ans[i]<<endl;
	}
	return 0;
}

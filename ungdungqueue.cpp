//1 2 1 3 4 k=3
//2 3 4 
//chen tin nhan
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int a[n];
	for(int &x:a) cin>>x;
	int k;cin>>k;
	//tao mang danh dau
	bool b[10001];
	queue<int> dq;
	memset(b,false,sizeof(b));
	for(int i=0;i<n;i++){
		//a[i]
		if(!b[a[i]]){
			if(dq.size()<k){
				dq.push(a[i]);
				b[a[i]]=true;
			}else{
				b[dq.front()]=false;
				b[a[i]]=true;
				dq.push(a[i]);
				dq.pop();
			}
		}
	}
	while(!dq.empty()){
		cout<<dq.front()<<" ";
		dq.pop();
	}
	return 0;
}

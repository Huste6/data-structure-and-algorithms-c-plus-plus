#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001][1001];
vector<int> adj[1001];
vector<pair<int,int>> edges;
int main(){
	/*chuyen tu danh sach canh sang danh sach ke
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	//chuyen danh sach canh sang danh sach ke
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1;i<=m;i++){
		cout<<i<<" : ";
		for(int x:adj[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	//chuyen ma tran ke sang danh sach canh
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j] && i<j){
				edges.push_back({i,j});
			}
		}
	}
	for(auto it:edges){
		cout<<it.first<<" "<<it.second<<endl;
	}
	//chuyen ma tran ke sang danh sach ke
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]){
				adj[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<i<<" : ";
		for(int x:adj[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}*/
	//chuyen danh sach ke sang ma tran ke
	cin>>n;
	cin.ignore();
	//neu danh sach ke co dau phay
	for(int i=1;i<=n;i++){
		string s;getline(cin,s);
		stringstream ss(s);
		string token;
		while(getline(ss,token,',')){
			a[i][stoi(token)]=1;
		}
		//neu k co dau phay
		//while(ss>>token){
		//	a[i][stoi(token)]=1;
		//}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

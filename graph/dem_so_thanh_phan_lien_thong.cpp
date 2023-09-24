#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[1001];
bool visited[1001];

void inp(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited,false,sizeof(visited));
}
void dfs(int u){
	cout<<u<<" ";
	visited[u]=true;
	for(int x:adj[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
}

int connectedComponent(){
	int ans=0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			++ans;
			cout<<"Cac dinh thuoc thanh phan lien thong: ";
			dfs(i);
		}
	}
	return ans;	
}
int main(){
	inp();
	cout<<connectedComponent();
	return 0;
}

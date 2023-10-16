#include<bits/stdc++.h>
using namespace std;
int n,m,st,ed;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void inp(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);	
	}
	memset(visited,false,sizeof(visited));
}
bool dfs(int u){
	visited[u]=true;
	for(int v:adj[u]){
		if(!visited[v]){
			parent[v]=u;
			if(dfs(v)) return true;
		}else if(v!=parent[u]){
			st=u,ed=v;
			return true;
		}
	}
	return false;
}

int main(){
	inp();
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			if(dfs(i)) {
				cout<<"YES\n"; 
				vector<int> cycle;cycle.push_back(st);
				while(ed!=st){
					cycle.push_back(ed);
					ed=parent[ed];
				}
				cycle.push_back(st);
				reverse(cycle.begin(),cycle.end());
				for(int x:cycle){
					cout<<x<<" ";
				}
				return 0;
			}	
		}
	}
	cout<<"NO\n";
	return 0;
}


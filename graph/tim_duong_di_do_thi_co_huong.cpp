#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[10001];
bool visited[10001];
void inp(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	memset(visited,false,sizeof(visited));
}
bool dfs(int u,int v){
	visited[u]=true;
	if(u==v) return true;
	for(int x:adj[u]){
		if(visited[x]) continue;
		if(dfs(x,v)){
			return true;
		}
	}
	return false;	
}
bool bfs(int u,int v){
	queue<int> q;
	q.push(u);
	visited[u]=true;
	if(u==v) return true;
	while(!q.empty()){
		int k=q.front();
		q.pop();
		for (int x : adj[k]){
			if(visited[x]) continue;
			if(bfs(x,v)){// if a path is found from x to v,
				return true;
			}
			//neu x chua duoc duyet
			if(!visited[x]){
				q.push(x);
				visited[x]=true;
			}
		}
	}
	return false;
}
int main(){
	inp();
	int u,v;cin>>u>>v;
	if(bfs(u, v)){ 
        cout << "There is a path from " << u << " to " << v << endl;
    }else{
        cout << "There is no path from " << u << " to " << v << endl;
    }
}

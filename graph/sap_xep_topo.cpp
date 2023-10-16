#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;

int n,m;
vector<int> adj[maxn];
bool visited[maxn];
vector<int> topo;
int in[maxn];//tinh ban bac vao

void inp(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		in[y]++;
	}
	memset(visited,false,sizeof(visited));
}
void dfs(int u){
	visited[u]=true;
	for(int x:adj[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
	topo.push_back(u);
}
//thuat toan kahn
void kahn(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		topo.push_back(u);
		for(int x:adj[u]){
			in[x]--;
			if(in[x]==0){
				q.push(x);
			}
		}
	}
	for(int x:topo){
		cout<<x<<" ";
	}
}
/*
int main(){
	inp();
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	reverse(topo.begin(),topo.end());
	for(int x:topo){
		cout<<x<<" ";
	}
	return 0;
}*/
int main(){
	inp();
	kahn();
	return 0;
}

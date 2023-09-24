#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool visited[1001];

void inp(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited,false,sizeof(visited));
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u]=true;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		cout<<v<<" ";
		for (int x : adj[v]){
			//neu x chua duoc duyet
			if(!visited[x]){
				q.push(x);
				visited[x]=true;
			}
		}
	}
}
void dfs(int u){
	cout<<u<<" ";
	visited[u]=true;
	for (int v : adj[u]){
		if(visited[v]) continue;
		if(!visited[v]){
			dfs(v);
		}
	}
}
//su dung stack cai dat dfs
void dfs1(int start){
	stack<int> st;
	st.push(start);
	while(!st.empty()){
		int v=st.top();
		st.pop();
		visited[v]=true;
		for(int u:adj[v]){
			if(visited[u]) continue;
			st.push(u);
		}
	}
}
int main(){
	inp();
	//dfs(1);
	bfs(1);
	return 0;
}
/*bool dfs(int u, int x){ 
    visited[u] = true; 
    if(u == x){
        return true; // if current vertex is the destination
    }

    for (int v : adj[u]){ 
        if(visited[v]) continue; 
        if(dfs(v, x)){ // if a path is found from v to x, return true
            return true;
        }
    } 
    return false; 
} 

int main(){ 
    inp(); 
    int u, x;
    cin >> u >> x; // input the vertices u and x

    if(dfs(u, x)){ 
        cout << "There is a path from " << u << " to " << x << endl;
    }else{
        cout << "There is no path from " << u << " to " << x << endl;
    }

    return 0; 
} */

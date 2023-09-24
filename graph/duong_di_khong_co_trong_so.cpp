
#include<bits/stdc++.h>
using namespace std;

bool visited[1001];
int n, m, s, t;
vector<int> adj[1001];
int parent[1001];

void inp(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
}

void dfs(int u){
    visited[u] = true;

    for(int v : adj[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
    }
}

void printPath(int s, int t){
    dfs(s);

    if(!visited[t]){
        cout << "Khong co duong di";
    } else {
        vector<int> path;
        while(t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());

        for(int x : path){
            cout << x << " ";
        }
    }
}

void printPathBFS(int s, int t){
    bfs(s);

    if(!visited[t]){
        cout << "Khong co duong di";
    } else {
        vector<int> path;
        while(t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());

        for(int x : path){
            cout << x << " ";
        }
    }
}

int main(){
    inp();
    cin >> s >> t;

    //cout << "Duyet theo DFS: ";
    //printPath(s, t);
    //cout << endl;

    cout << "Duyet theo BFS: ";
    printPathBFS(s, t);

    return 0;
}



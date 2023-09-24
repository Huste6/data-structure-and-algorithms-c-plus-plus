#include<bits/stdc++.h>
using namespace std;

char a[1001][1001];
int n, m;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool visited[1001][1001];

void dfs(int i, int j){
    cout << i << " " << j << endl;
    visited[i][j] = true;
    // Duyet cac dinh ke
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1]){
            dfs(i1, j1);
        }
    }
}

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    cout << i << " " << j << endl;
    while(!q.empty()){
        pair<int, int> top = q.front();
        q.pop();
        for(int k = 0; k < 4; k++){
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1]){
                cout << i1 << " " << j1 << endl;
                q.push({i1, j1});
                visited[i1][j1] = true;
            }
        }
    }
}

void inp(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 'x' && !visited[i][j]){
                cout << "thanh phan lien thong thu " << cnt+1 << " :" << endl;
                //dfs(i, j);
                bfs(i, j);
                cnt++;
            }
        }
    }
    // cout << cnt << endl;
}

int main(){
    inp();
    return 0;
}



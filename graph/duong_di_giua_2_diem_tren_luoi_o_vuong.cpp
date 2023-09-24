#include<bits/stdc++.h>
using namespace std;
int n,m,x1,y1;
bool visited[1001][1001];
char a[1001][1001];

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
bool dfs(int i,int j){
	cout<<i<<" "<<j<<endl;
	if(a[i][j]=='B'){
		return true;
	}
	//duong di di theo ki tu o
	a[i][j]='x';
	for(int k=0;k<4;k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if(i1>=1 && i1<=n &&j1>=1 && j1<=n && a[i1][j1]!='x'){
			//neu co duong di
			if(dfs(i1,j1)) return true;
		}
	}
	return false;
}
bool bfs(int i,int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	a[i][j]='x';
	cout<<i<<" "<<j<<endl;
	while(!q.empty()){
		pair<int,int> top=q.front();q.pop();
		for(int k=0;k<4;k++){
			int i1=top.first+dx[k];
			int j1=top.second+dy[k];
			if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1]!='x'){
				cout<<i1<<" "<<j1<<endl;
				if(a[i1][j1]=='B') return true;
				q.push({i1,j1});
				a[i1][j1]='o';
			}
		}
	}
	return false;
}
void inp(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j]=='A'){
            	x1=i;y1=j;
			}
        }
    }
    //if(dfs(x1,y1)) cout<<"Yes\n";
    //else cout<<"No\n";
    if(bfs(x1,y1)) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
	inp();
	return 0;
}

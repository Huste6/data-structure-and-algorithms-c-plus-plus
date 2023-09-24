#include<bits/stdc++.h>
using namespace std;
int n,m,x1,y1,x2,y2;
char a[1001][1001];
int d[1001][1001];//luu duong di tu A den B
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0}; 
void bfs(int i,int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	a[i][j]='x';
	d[i][j]=0;
	cout<<i<<" "<<j<<endl;
	while(!q.empty()){
		pair<int,int> top=q.front();q.pop();
		for(int k=0;k<4;k++){
			int i1=top.first+dx[k];
			int j1=top.second+dy[k];
			if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1]!='x'){
				cout<<i1<<" "<<j1<<endl;
				d[i1][j1]=d[top.first][top.second]+1;
				if(a[i1][j1]=='B'){
					return;
				}
				q.push({i1,j1});
				a[i1][j1]='x';
			}
		}
	}
}
void inp(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='A'){
				x1=i;y1=j;
			}else if(a[i][j]=='B'){
				x2=i;y2=j;
			}
		}
	}
	bfs(x1,y1);
	if(!d[x2][y2]) cout<<"khong co duong di!\n";
	else cout<<d[x2][y2]<<endl;
}
int main(){
	inp();
}

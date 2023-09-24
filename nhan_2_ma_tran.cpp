#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>a[i][j];
	}
	int n1,m1;cin>>n1>>m1;
	int b[n1][m1];
	for(int i=0;i<n1;i++){
		for(int j=0;j<m1;j++) cin>>b[i][j];
	}
	//m=n1;
	int c[n][m1];
	for(int i=0;i<n;i++){
		for(int j=0;j<m1;j++){
			int sum = 0;
            for (int k = 0; k < m; k++) {
                sum += a[i][k] * b[k][j];
            }
            cout<<sum<<" ";
		}
		cout<<endl;
	}
}

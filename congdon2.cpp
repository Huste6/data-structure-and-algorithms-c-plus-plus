#include<bits/stdc++.h>
using namespace std;
//cong don mang 2 chieu
/*4 4
1 2 3 4
5 6 7 8
2 2 1 3
5 6 7 8
1 
1 3 1 4
output: 44
prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+A[i][j]
*/
int main(){
	int n,m;cin>>n>>m;
	int a[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>a[i][j];
	}
	int q;cin>>q;
	/*while(q--){
		int h1,h2,c1,c2;
		cin>>h1>>h2>>c1>>c2;
		int sum=0;
		for(int i=h1;i<=h2;i++){
			for(int j=c1;j<=c2;j++){
				sum+=a[i][j];
			}
		}
		cout<<sum<<endl;
	}*/
	int pre[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
		}
	}
	while(q--){
		int h1,h2,c1,c2;cin>>h1>>h2>>c1>>c2;
		cout<<pre[h2][c2]-pre[h1-1][c2]-pre[h2][c1-1]+pre[h1-1][c1-1]<<endl;
	}
	return 0;
}

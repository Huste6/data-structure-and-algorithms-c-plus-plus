/*
4
0 20 35 10
20 0 90 50
35 90 0 12
10 50 12 0
*/
#include<bits/stdc++.h>
using namespace std;
int chuaxet[100];
int n;
long cmin=100000000;
long c[20][20];
long s=0;//khoi tao so tien
long MIN=100000000;
long x[100];
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]!=0){
				cmin=min(cmin,c[i][j]);
			}
		}
	}
}
void Try(int i){
	if(s+cmin*(n-i+1)>=MIN) return;
	for(int j=2;j<=n;j++){
		if(chuaxet[j]){
			x[i]=j;
			chuaxet[j]=0;
			s+=c[x[i-1]][x[i]];
			if(i==n){
				if(s+c[x[n]][x[1]]<MIN){
					MIN=s+c[x[n]][x[1]];
				}
			}else{
				Try(i+1);
			}
			s-=c[x[i-1]][x[i]];
			chuaxet[j]=1;
		}
	}
}
int main(){
	memset(chuaxet,1,sizeof(chuaxet));
	chuaxet[1]=0;
	x[1]=1;
	nhap();
	Try(2);
	cout<<MIN;
	return 0;
}

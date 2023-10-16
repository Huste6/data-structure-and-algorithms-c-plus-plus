#include<bits/stdc++.h>
using namespace std;
#define MAX 8
int A[MAX][MAX]={0};
int X[8]={-2,-2,-1,-1,1,1,2,2};
int Y[8]={-1,1,-2,2,-2,2,-1,1};
int n;//so phan tu cua ban co muon tao
int dem=0;
void xuat(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

void dichuyen(int x,int y){
	++dem;
	A[x][y]=dem;
	//di chuyen ma den 8 o
	for(int i=0;i<8;i++){
		//kiem tra ma da di het ban co chua
		if(dem==n*n){
			cout<<"Cac buoc da di:\n";
			xuat();
			exit(0);
		}
		//neu chua di het ban co
		int x1=x+X[i];
		int y1=y+Y[i];
		//keim tra x1 y1 hop le hay khong
		if(x1>=0&&y1>=0&&x1<n&&y1<n&&A[x1][y1]==0){
			dichuyen(x1,y1);
		}	
	}	
	//neu khong tim duoc buoc di
	--dem;
	A[x][y]=0;
}
int main(){
	cout<<"Nhap n: ";cin>>n;
	int a,b;
	cout<<"nhap 2 vi tri bat dau: ";cin>>a>>b;
	dichuyen(a,b);
	cout<<"khong tim thay duong di!";
}

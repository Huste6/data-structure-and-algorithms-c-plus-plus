#include<bits/stdc++.h>
using namespace std;
/*sap xep bang doi cho truc tiep
vd: 5 7 3 2 
buoc 1: 2 7 5 3
buoc 2: 2 3 7 5
buoc 3: 2 3 5 7*/

int main(){
	int n;cin>>n;
	int a[n];
	for(int &x:a) cin>>x;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
		cout<<"Buoc "<<i+1<<":";
		for(int x:a){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
int n,k,a[100];
set<int> se;
void next(){
	int i=k;
	while(i>=1 && a[i]==n-k+i){
		--i;
	}
	if(i==0){
		cout<<k<<endl;
	}else{
		a[i]--;
		for(int j=i+1;j<=k;j++){
			a[j]=a[j-1]+1;
		}
		int cnt=0;
		for(int i=1;i<=k;i++){
			if(se.find(a[i])==se.end()){
				++cnt;
			}
		}
		cout<<cnt<<endl;
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		se.insert(a[i]);
	}
	next();
	return 0;
}

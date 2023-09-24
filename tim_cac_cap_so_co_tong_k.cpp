#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,m;cin>>n>>m;
	long long a[n];
	for(long long &x:a) cin>>x;
	sort(a,a+n);
	int cnt=0;
	int i=0,j=n-1;
	while(i<j){
		if(a[i]+a[j]==m){
			cnt++;
			++i;
		}else if(a[i]+a[j]<m){
			++i;
		}else{
			--j;
		}
	}
	cout<<cnt<<endl;
}

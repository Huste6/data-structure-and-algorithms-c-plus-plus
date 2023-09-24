#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int b[n],c[n];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(b+1,b+n+1);sort(c+1,c+n+1);
	int res=1e9;
	int i=1,j=n;
	//i chay trong b
	//j chay trong c
	while(i<=n && j>=1){
		if(res>abs(b[i]+c[j])) res=abs(b[i]+c[j]);
		if(res==0) break;
		if(b[i]+c[j]>=0) --j;
		else ++i;
	}
	cout<<res;
	return 0;
}

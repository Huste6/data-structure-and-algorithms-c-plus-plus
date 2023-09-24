#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		int a[n],b[m];
		for(int &i:a) cin>>i;
		set<int> se;
		for(int i=0;i<m;i++){
			int x;cin>>x;
			se.insert(x);
		}
		bool ok=false;
		for(int x:a){
			if(se.find(x)==se.end()){
				cout<<x<<" ";
				ok=true;
			}
		}
		if(!ok) cout<<"NOT FOUND!\n";
		else cout<<endl;
	}
}

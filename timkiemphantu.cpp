#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    /*cach 1:
	while(t--){
    	int n;cin>>n;
    	int a[n];
    	for(int &i:a) cin>>i;
    	sort(a,a+n);//sap xep
    	int q;cin>>q;
    	while(q--){
    		int x;cin>>x;
    		if(binary_search(a,a+n,x)) cout<<"YES\n";
    		else cout<<"NO\n";
		}
	}
	*/
	while(t--){
		int n;cin>>n;
		set<int> se;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			se.insert(x);
		}
		int q;cin>>q;
		while(q--){
			int x;cin>>x;
			if(se.count(x)==1) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	
}


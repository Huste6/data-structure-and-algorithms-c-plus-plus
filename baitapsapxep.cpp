/*tim so cap trong 1 mang co tong bang k
c1.#include<bits/stdc++.h>
using namespace std;
//1 2 2 4 3 3-> k=5  -> 5  (1+2+2+2+2+1)/2
//1 2 2 2 2 3-> k=4  -> 7  (1+3+3+3+3+1)/2 
int main(){
	int n,k;cin>>n>>k;
	map<int,int> mp;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=mp[k-a[i]];
		if(a[i]*2==k) --cnt;
	}
	cout<<cnt/2<<endl;
}
c2.
#include<bits/stdc++.h>
using namespace std;
int first_pos(int a[],int l,int r,int x){
	int res=-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			res=m;
			r=m-1;
		}
		else if(a[m]>x) r=m-1;
		else l=m+1;
	}
	return res;
}
int last_pos(int a[],int l,int r,int x){
	int res=-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			res=m;l=m+1;
		}else if(a[m]>x) r=m-1;
		else l=m+1;
	}
	return res;
}
int main(){
	int n,k;cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n;i++){
		int l=first_pos(a,i+1,n-1,k-a[i]);
		int r=last_pos(a,i+1,n-1,k-a[i]);
		if(l!=-1){
			ans+=r-l+1;
		}
	}
	// 1 2 2 2 2 3 -> k=4 -> 7 
	cout<<ans<<endl;
}
//tim so cap trong 1 mang co tong nho hon hoac bang k
#include<bits/stdc++.h>
using namespace std;
//tim vi tri cuoi cung cua phan tu nho hon x
int last_pos(int a[],int l,int r,int x){
	int res=-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]<x){
			l=m+1;
			res=m;
		}else{
			r=m-1;
		}
	}
	return res;
}
// 1 2 3 4 5 -> 6
int main(){
	int n,k;cin>>n>>k;
	int a[n];
	for(int &x:a) cin>>x;
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n-1;i++){
		//a[j] < k - a[i]  tim  a[j]
		int l=last_pos(a,i+1,n-1,k-a[i]);
		if(l!=-1){
			ans+=l-i;
		}
	}
	cout<<ans;
}
//tim so cap trong 1 mang co tong lon hon k
#include<bits/stdc++.h>
using namespace std;
//tim vi tri dau tien lon hon x
int first_pos(int a[],int l,int r,int x){
	int res=-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]>x){
			r=m-1;
			res=m;
		}else{
			l=m+1;
		}
	}
	return res;
}
int main(){
	int n,k;cin>>n>>k;
	int a[n];
	for(int &x:a) cin>>x;
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n-1;i++){
		int l=first_pos(a,i+1,n-1,k-a[i]);
		if(l!=-1){
			ans+=n-l;
		}
	}
	cout<<ans<<endl;
}
//tach tung chu so trong  1 chuoi so 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cin.ignore();
		string s;getline(cin,s);
		int a[10]={0};
		for(char x:s){
			if(isdigit(x)){
				a[x-'0']=1;
			}
		}
		for(int i=0;i<10;i++){
			if(a[i]) cout<<i<<" ";
		} 
		cout<<endl;
	}
}
//sap xep theo tan so
#include<bits/stdc++.h>
using namespace std;
int a[1000],n;
map<int,int> mp;
bool cmp(int a,int b){
	if(mp[a]!=mp[b]){
		return mp[a]>mp[b];
	}
	return a<b;
}
int main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
			mp[a[i]]++;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		mp.clear();
	}
}
tim giao cua 3 mang
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n,m,k;cin>>n>>m>>k;
		int a[n],b[m],c[k];
		for(int &x:a) cin>>x;
		for(int &x:b) cin>>x;
		for(int &x:c) cin>>x;
		int i=0,j=0,l=0;
		vector<int> vt;
		while(i<n && j<m && l<k){
			if(a[i]==b[j] && b[j]==c[l]){
				vt.push_back(a[i]);++i;++j;++l;
			}else if(a[i]<=b[j] && a[i]<=c[l]){
				++i;
			}else if(b[j]<=a[i] && b[j]<=c[l]){
				++j;
			}else ++l;
		}
		if(vt.size()==0) cout<<"-1\n";
		else{
			for(int x:vt){
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}*/


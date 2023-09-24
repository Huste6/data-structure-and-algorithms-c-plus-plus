#include<bits/stdc++.h>
using namespace std;
int search1(int a[],int n,int find){
	int l=0,h=n-1,mid;
	while(a[l]!=a[h] && find>=a[l] && find<=a[h]){
		mid=l+((find-a[l])*(h-l))/(a[h]-a[l]);
		if(find==a[mid]) return mid;
		else if(find<a[mid]) h=mid-1;
		else l=mid+1;
	}
	if(find==a[l]) return l;
	else return -1;
}
int main(){
	int n,find;cin>>n>>find;
	int a[n];
	for(int &x:a) cin>>x;
	sort(a,a+n);
	int pos=search1(a,n,find);
	if(pos!=-1) cout<<"FIND!\n";
	else cout<<"NO FIND\n";
}

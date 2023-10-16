#include<bits/stdc++.h>
using namespace std;
int limit;
bool check(int k,vector<int>& piles){
	long hours=0;
	for(double x:piles){
		hours+=ceil(x/k);
	}
	return hours<=limit;
}
int minEatingSpeed(vector<int>&piles,int h){
	limit=h;
	int l=1,r=0;
	for(int x:piles){
		r=max(r,x);
	}
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,piles)) r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main(){
	vector<int> piles={2,5,6,10};
	cout<<minEatingSpeed(piles,5);
	return 0;
}

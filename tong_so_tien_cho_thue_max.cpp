#include<bits/stdc++.h>
using namespace std;
struct Orders{
	int start;
	int duration;
	int price;
};
bool cmp(const Orders& order1, const Orders& order2){
	return order1.start<order2.start;
}
int maximizeRevenue(vector<Orders>& orders,int maintenanceDays){
	sort(orders.begin(),orders.end(),cmp);
	int n=orders.size();
	vector<int> dp(n);//luu tong so tien thu duoc o moi vi tri
	dp[0]=orders[0].price;
	for(int i=1;i<n;i++){
		dp[i]=orders[i].price;
		for(int j=0;j<i;j++){
			if(orders[i].start >= orders[j].start+orders[j].duration+maintenanceDays){
				dp[i]=max(dp[i],dp[j]+orders[i].price);
			}
		}
	}
	int maxRevenue=0;
	for(int i=0;i<n;i++){
		maxRevenue=max(maxRevenue,dp[i]);
	}
	return maxRevenue;
}
int main(){
	int n,maintenanceDays;
	cin>>n>>maintenanceDays;
	vector<Orders> orders(n);
	for(int i=0;i<n;i++){
		cin>>orders[i].start>>orders[i].duration>>orders[i].price;
	}
	int maxRevenue=maximizeRevenue(orders,maintenanceDays);
	cout<<"Maximized revenue: "<<maxRevenue;
	return 0;
}

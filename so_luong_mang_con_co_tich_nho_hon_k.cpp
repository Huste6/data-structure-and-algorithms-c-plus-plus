#include<bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums,int k){
	if(k<=1) return 0;
	int ans=0,curr=1,l=0;
	for(int right=0;right<nums.size();right++){
		curr*=nums[right];
		while(curr>=k){
			curr/=nums[l];
			l++;
		}
		ans+=right-l+1;
	}
	return ans;
}
int main(){
	vector<int> nums={10,5,2,6};
	cout<<numSubarrayProductLessThanK(nums,100);
	return 0;
}

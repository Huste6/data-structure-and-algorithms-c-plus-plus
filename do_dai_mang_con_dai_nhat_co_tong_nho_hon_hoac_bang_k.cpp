#include<bits/stdc++.h>
using namespace std;
int findLength(vector<int>&nums,int k){
	int l=0,curr=0,ans=0;
	for(int right=0;right<nums.size();right++){
		curr+=nums[right];
		while(curr>k){
			curr-=nums[l];
			l++;
		}
		ans=max(ans,right-l+1);
	}
	return ans;
}
int main(){
	vector<int> nums={3, 1, 2, 7, 4, 2, 1, 1, 5};
	cout<<findLength(nums,8);
	return 0;
}

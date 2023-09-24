#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums,int k){
	vector<int> ans;
	deque<int> dq;
	for(int i=0;i<nums.size();i++){
		while(!dq.empty() && nums[i]>nums[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
		if(dq.front()+k==i){
			dq.pop_front();
		}
		if(i>=k-1){
			ans.push_back(nums[dq.front()]);
		}
	}
	return ans;
}
int main(){
	vector<int> nums={1,3,-1,-3,5,3,6,7};
	vector<int> result=maxSlidingWindow(nums,3);
	for(auto it:result){
		cout<<it<<" ";
	}
	return 0;
}

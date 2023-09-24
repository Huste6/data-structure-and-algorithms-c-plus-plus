#include<bits/stdc++.h>
using namespace std;
vector<int> findNextGreater(vector<int>& nums){
	vector<int> ans(nums.size(),-1);
	stack<int> st;
	int n=nums.size();
	for(int i=0;i<2*n;i++){
		int num=nums[i%n];
		while(!st.empty() && nums[st.top()]<num){
			ans[st.top()]=num;
			st.pop();
		}
		if(i<n){
			st.push(i);
		}
	}
	return ans;
}
int main(){
	vector<int> nums={1,2,3,4,3};
	vector<int> result=findNextGreater(nums);
	for(auto it:result){
		cout<<it<<" ";
	}
	return 0;
}

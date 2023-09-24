#include<bits/stdc++.h>
//cho mang so nguyen num, co bao nhieu cach chia mang thanh 2 phan sao cho tong cua phan ben trai lon hon hoac bang ben phai va phan ben phai co it nhat 1 phan tu
using namespace std;
int waysToSplitArray(vector<int> nums){
	vector<int> prefix={nums[0]};
	for(int i=1;i<nums.size();i++){
		prefix.push_back(prefix.back()+nums[i]);
	}
	int ans=0;
	for(int i=0;i<int(nums.size())-1;i++){
		long leftSelection=prefix[i]-prefix[0]+nums[0];
		//long rightSelection=prefix.back()-prefix[i];
		long rightSelection=prefix.back()-prefix[i+1]+nums[i+1];
		if(leftSelection >= rightSelection){
			cout<<nums[0]<<" "<<nums[i]<<endl;
			ans++;
		}
	}
	return ans;
}
int main(){
	vector<int> nums;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		nums.push_back(x);
	}
	cout<<waysToSplitArray(nums);
	return 0;
}

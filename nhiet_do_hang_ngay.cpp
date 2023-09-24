//tim so ngay phai doi de nhiet do am hon nhiet do hien tai
#include<bits/stdc++.h>
//40,35,32,37,50
// 0  1 2  3  4
//->4 2 1 1 0

using namespace std;
vector<int> dailytemperatures(vector<int>& temperatures){
	stack<int> stack;
	vector<int> ans(temperatures.size());
	for(int i=0;i<temperatures.size();i++){
		while(!stack.empty() && temperatures[stack.top()]<temperatures[i]){
			int j=stack.top();
			ans[j]=i-j;
			stack.pop();
		}
		stack.push(i);
	}
	return ans;
}
int main(){
	vector<int> temperatures={40,35,32,37,50};
	vector<int> result=dailytemperatures(temperatures);
	for(auto it:result){
		cout<<it<<" ";
	}
	return 0;
}

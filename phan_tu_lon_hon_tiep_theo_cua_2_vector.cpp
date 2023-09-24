#include<bits/stdc++.h>
using namespace std;
//O(m*n)
vector<int> findNextGreater(vector<int>& nums1,vector<int>& nums2){
	vector<int> ans(nums1.size());
	unordered_map<int,int> mp;
	for(int i=0;i<nums2.size();i++){
		mp[nums2[i]]=i;
	}
	for(int i=0;i<nums1.size();i++){
		int x=nums1[i];
		if(mp.count(x)){
			int j=mp[x];
			for(int k=j+1;k<nums2.size();k++){
				if(nums2[k]>x){
					ans[i]=nums2[k];
					break;
				}
			}
		}
	}
	return ans;
}
//O(m+n)
vector<int> findNextGreater1(vector<int>& nums1,vector<int>& nums2){
	vector<int> ans(nums1.size());
	unordered_map<int,int> mp;
	stack<int> st;
	for(int i=0;i<nums2.size();i++){
		while(!st.empty() && st.top()<nums2[i]){
			mp[st.top()]=nums2[i];
			st.pop();
		}
		st.push(nums2[i]);
	}
	while(!st.empty()){
		mp[st.top()]=-1;
		st.pop();
	}
	for(int i=0;i<nums1.size();i++){
		ans[i]=mp[nums1[i]];
	}
	return ans;
}
int main(){ 
    string s1;
    getline(cin,s1); 
    vector<int> nums1; 
    vector<int> nums2; 
    int number1; 
    int number2; 
    stringstream ss(s1); 
    while(ss>>number1){ 
        nums1.push_back(number1); 
    } 
    string s2;
    getline(cin,s2); 
    stringstream ss2(s2);
    while(ss2>>number2){ 
        nums2.push_back(number2); 
    } 
    vector<int> ans=findNextGreater(nums1,nums2); 
    for(int i=0;i<ans.size();i++){
      if(ans[i]==0){
        cout<<"-1";
      }else{
        cout<<ans[i];
      }
      if(i!=ans.size()-1){
        cout<<" ";
      }
    }
    return 0; 
}

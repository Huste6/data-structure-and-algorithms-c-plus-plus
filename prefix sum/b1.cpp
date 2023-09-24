#include<bits/stdc++.h>
using namespace std;
//cho 1 mang nums,1 mang queries trong do queries[i]=[x,y] va 1 so nguyen limit tao mang boolen
//nums=[1,6,3,2,7,2]
//queries=[[0,3],[2,5],[2,4]]
//limit=13
//output:[true,false,true]

vector<int> solve(vector<int> nums,vector<vector<int>> queries,int limit){
  vector<int> prefix = {nums[0]};
  for(int i=1; i<nums.size(); i++){
    prefix.push_back(prefix.back() + nums[i]);
  }
  vector<int> ans;
  for(vector<int>& query: queries){
    int x = query[0], y = query[1];
    int curr = prefix[y] - prefix[x] + nums[x];
    ans.push_back(curr < limit);
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  vector<int> nums;
  for(int i=0; i<n; i++){
  	  int x;
    cin >> x;
    nums.push_back(x);
  }
  
  int m;
  cin >> m;
  vector<vector<int>> queries;
  for(int i=0; i<m; i++){
    int x, y;
    cin >> x >> y;
    queries.push_back({x, y});
  }
  
  int limit;
  cin>> limit;
  
  vector<int> result = solve(nums, queries, limit);
  for(int i=0; i<result.size(); i++){
    cout << result[i] << " ";
  }
  
  return 0;
}

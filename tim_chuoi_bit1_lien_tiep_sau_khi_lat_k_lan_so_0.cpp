#include<bits/stdc++.h>
using namespace std;

int longgestbits_1(vector<int> nums,int k){
  int l=0,r=0;
  int zeroCount=0;
  int maxLength=0;
  while(r<nums.size()){
    if(nums[r]==0){
      zeroCount++;
    }
    while(zeroCount>k){
      if(nums[l]==0){
        zeroCount--;
      }
      l++;
    }
    maxLength=max(maxLength,r-l+1);
    r++;
  }
  return maxLength;
}
int main(){
  string s;getline(cin,s);
  int number;
  vector<int> nums;
  stringstream ss(s);
  while(ss>>number){
    nums.push_back(number);
  }
  int k;cin>>k;
  cout<<longgestbits_1(nums,k);
}


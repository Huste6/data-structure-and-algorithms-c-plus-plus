#include<bits/stdc++.h>
using namespace std;
void solve(vector<pair<int,int>>& v){
  sort(v.begin(),v.end());
  int cnt = 1;
  int ans = 1;
  int i = 1, j=0;
  int n = v.size();
  while (i < n && j < n) {
      if (v[i].first < v[j].second) {
          cnt++;
          i++;
          if (cnt > ans) {
              ans = cnt;
          }
      } else {
          cnt--;
          j++;
      }
  }
  cout << ans << endl;
}
int main(){
  string s1,s2;
  getline(cin,s1);
  getline(cin,s2);
  int num;
  vector<int> v1,v2;
  vector<pair<int,int>> v;
  stringstream ss1(s1);
  stringstream ss2(s2);
  while(ss1>>num){
    v1.push_back(num);
  }
  while(ss2>>num){
    v2.push_back(num);
  }
  for(int i=0;i<v1.size();i++){
    v.push_back({v1[i],v2[i]});
  }
  solve(v);
  return 0;
}

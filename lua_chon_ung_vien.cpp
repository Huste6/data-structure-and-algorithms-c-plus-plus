#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<string,int> s1,pair<string,int> s2){
  if(s1.second==s2.second) return s1.first<s2.first;
  return s1.second>s2.second;
}
int main(){
  int n,m;cin>>n>>m;
  vector<pair<string,int>> v;
  string s;int k;
  while(n--){
    cin>>s>>k;
    v.push_back({s,k});
  }
  sort(v.begin(),v.end(),cmp);
  for(int i=0;i<m;i++){
    cout<<v[i].first<<endl;
  }
}

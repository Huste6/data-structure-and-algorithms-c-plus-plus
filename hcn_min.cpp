#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> v1,pair<int,int> v2){
	return v1.first<v2.first;
}
bool cmp1(pair<int,int> v1,pair<int,int> v2){
	return v1.second<v2.second;
}
int main(){
	int n;cin>>n;
	int x1,y1,x2,y2;
	vector<pair<int,int>> v;
	int cnt=0;//dem so dinh
	while(n--){
		cin>>x1>>y1;
		v.push_back({x1,y1});
		cnt++;
		cin>>x2>>y2;
		v.push_back({x2,y2});
		cnt++;
	}
	sort(v.begin(),v.end(),cmp);
	int xmin=v[cnt-1].first-v[0].first;
	sort(v.begin(),v.end(),cmp1);
	int ymin=v[cnt-1].second-v[0].second;
	cout<<xmin*ymin<<endl;
	return 0;
}

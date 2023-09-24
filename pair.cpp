#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	//pair<int,int> v=make_pair(100,200);
	//pair<int,int> v={100, 200};
	//cout<<v.first<<endl;
	//cout<<v.second<<endl;
	//pair<pair<int,int>,int>;
	//tuple<int,int,int> t{1,2,3};
	//cout<< get<0>(t) <<endl;
	tuple<string,int,string> t=make_tuple("java",100,"python");
	cout<< get<0>(t) <<endl;
	cout<< get<1>(t) <<endl;
	cout<< get<2>(t) <<endl;
	return 0;
}
	

#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return abs(a)<abs(b);
}
//lower_bond
//upper_bound
//memset
//fill
//merge
//set_union la hop 2 mang
//set_intersection la giao 2 mang
//set_diffrence  thuoc 1 mang ma khong thuoc mang con lai
//set_symmetric_difference la cac phan tu khong thuoc phan hop cua 2 mang

int main(){
	/*
	cout<<max(1,20)<<endl;
	int a[5]={1,2,1,4,8};
	cout<<*min_element(a,a+5)<<endl;
	vector<int> b={1,2,1,4,8};
	cout<<*max_element(b.begin(),b.end())<<endl;
	int sum=accumulate(a,a+5,0);
	cout<<sum<<endl;
	//swap(a,b);
	sort(a,a+5);//a+x,x+y+1
	for(int x:a) cout<<x<<" ";
	cout<<endl;
	sort(b.begin(),b.end(),greater<int>());
	for(int x:b) cout<<x<<" ";
	cout<<endl;
	int a[5]={1,2,-1,4,8};
	stable_sort(a,a+5,cmp);
	for(int x:a) cout<<x<<" ";
	int a[5]={1,2,1,4,8};
	auto it=find(a,a+5,3);
	if(it==a+5) cout<<"NOT FOUND\n";
	else cout<<"FOUND\n";
	vector<int> b={1,2,1,3,5};
	auto it1=find(b.begin(),b.end(),5);
	if(it==b.end) cout<<"NOT FOUND\n";
	else cout<<"FOUND\n";
	int a[5]={1,2,1,4,8};
	if(binary_search(a, a+5, 2)) cout<<"Found\n";
	else cout<<"Not Found\n";
	vector<int> b={1,2,1,3,5};
	if(binary_search(b.begin(),b.end(),1)) cout<<"FOUND\n";
	else cout<<"NOT FOUND\n";
	int a[5]={1,2,3,4,5};
	memset(a,0,sizeof(a));
	vector<int> a(10);
	fill(a.begin(),a.end(),1000);
	vector<int> a ={1,2,3,3,4};
	vector<int> b={1,1,2,5,10,15};
	vector<int> res(11);
	merge(a.begin(),a.end(),b.begin(),b.end(),res.begin());
	for(int x:res) cout<<res<<" ";*/
	//set chu y phai sort moi dung
	int a[]={1,2,3,4,5};
	int b[]={1,3,4,5,6,7};
	vector<int> u(11);
	vector<int> v(11);
	vector<int> k(11);
	vector<int> c(11);
	auto it=set_union(a,a+5,b,b+6,u.begin());
	auto it1=set_intersection(a,a+5,b,b+6,v.begin());
	auto it2=set_difference(a,a+5,b,b+6,k.begin());
	auto it3=set_symmetric_difference(a,a+5,b,b+6,c.begin());
	v.resize(it1-v.begin());
	u.resize(it-u.begin());
	k.resize(it2-k.begin());
	c.resize(it3-c.begin());
	for(int x:u) cout<<x<<" ";
	cout<<endl;
	for(int x:v) cout<<x<<" ";
	cout<<endl;
	for(int x:k) cout<<x<<" ";
	cout<<endl;
	for(int x:c) cout<<x<<" ";
	cout<<endl;
}

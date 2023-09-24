#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//sort 
//stable_sort
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
bool cmp1(int a,int b){
	return abs(a)<abs(b);
}
bool cmp2(string a,string b){
	if(a.size()!=b.size()) return a.size()>b.size();
	else return a<b;
}
int main(){
	int n;cin>>n;
	/*int a[n];
	for(int &x:a) cin>>x;
	sort(a,a+n);//sap xep tang dan
	sort(a,a+n,greater<int>());
	sort(a,a+n,cmp); //cmp co chuc nang sap xep theo  thu tu giam dan
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}*/
	//co the sap xep string
	/*string s;
	getline(cin,s);
	sort(s.begin(),s.end());
	cout<<s<<endl;*/
	//sap xep cac phan tu theo thu tu tang dan ve gia tri tuyet doi
	/*int a[n];
	for(int &x : a) cin>>x;
	stable_sort(a, a+n,cmp1);
	for(int x:a){
		cout<<x<<" ";
	}*/
	//sap xep cac tu theo thu tu theo chieu dai giam dan neu cung chieu dai thi in tu co thu tu tu dien nho hon
	string a[n];
	for(string &x : a) cin>>x;
	stable_sort(a, a+n,cmp2);
	for(string x:a){
		cout<<x<<" ";
	}
	
}

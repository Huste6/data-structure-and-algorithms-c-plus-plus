#include<bits/stdc++.h>
using namespace std;
//vector<kieu dulieu> ten_vector;
//push_back()
//size kich thuoc vecto
int main(){
	//vector<int> v;
	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//cout<< v.size()<<endl;
	//v.push_back(40);
	//cout<< v.size()<<endl;
	//cout<<"phan tu dau"<<v[0]<<endl;
	//cout<<"phan tu cuoi cung"<<v[v.size()-1]<<" "<<v.back()<<endl;
	//for(int i=0;i<v.size();i++)
	//for(int x : v) 
	//khai bao iterator
	//for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
	//	cout<<*it<<endl;
	//}
	//for(auto vector<int>::iterator it = v.begin(); it != v.end(); ++it){
	//	cout<<*it<<endl;
	//}
	//cout<<v[2]<<" "<<*(v.begin()+2)<<endl;
	//int n;cin>>n;
	//vector<int> v(n,100);//mang co n phan tu
	string s=" ngon ngu  lap trinh c++";
	stringstream ss(s);
	string tmp;
	vector<string> v;
	while(ss >> tmp){
		v.push_back(tmp);
	}
	for(string x : v){
		cout<< x <<endl;
	}
	return 0;
}

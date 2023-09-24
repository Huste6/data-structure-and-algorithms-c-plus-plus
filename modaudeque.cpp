#include<iostream>
#include<deque>
using namespace std;

int main(){
	deque<int> dq;
	dq.push_back(1);
	dq.push_back(4);
	dq.push_front(3);
	dq.push_front(2);
	int length=dq.size();
	cout<<length<<endl;
	for(auto x:dq) cout<<x<<" ";
	cout<<endl;
	cout<<dq.front()<<endl;
	dq.pop_back();
	for(auto x:dq) cout<<x<<" ";
	cout<<endl;
	dq.pop_front();
	for(auto x:dq) cout<<x<<" ";
	cout<<endl;
	if(dq.empty()) cout<<"empty\n";
	else cout<<"not empty\n";
}

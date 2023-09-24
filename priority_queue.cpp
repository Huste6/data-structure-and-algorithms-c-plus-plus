#include<bits/stdc++.h>
using namespace std;
//priority_queue
//pop : xoa phan tu o dau
//top : lay phan tu o dau, mac dinh la lon nhat

int main(){
	/*priority_queue<int> pq;
	pq.push(1);
	pq.push(8);
	pq.push(3);
	pq.push(2);
	cout<<pq.top();
	pq.pop();
	cout<<pq.top();*/
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(1);
	pq.push(8);
	pq.push(3);
	pq.push(2);
	cout<<pq.top();
	
	return 0;
}

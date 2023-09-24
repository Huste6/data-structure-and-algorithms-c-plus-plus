#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
/*input:
2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10
output:
4 6 6 4
8 8 8 10*/
void printkmax(int a[],int n1,int n2){
	deque<int> dq;
	int max=0;
	for(int i=0;i<n1;i++){
		dq.push_back(a[i]);
		if(max<a[i]) max=a[i];
		if(dq.size()==n2){
			cout<<max<<" ";
			if(dq.front()==max){
				deque<int>::iterator it=dq.begin()+1;
				int temp=0;
				while(it!=dq.end()){
					if(temp<*it){
						temp=*it;
					}
					it++;
				}
				max=temp;
			}
			dq.pop_front();
		}
	}
	cout<<"\n";
}
int main(){
	int n;cin>>n;
	while(n--){
		int n1,n2;cin>>n1>>n2;
		int a[n1];
		for(int i=0;i<n1;i++) cin>>a[i];
		printkmax(a,n1,n2);
	}
	return 0;
}

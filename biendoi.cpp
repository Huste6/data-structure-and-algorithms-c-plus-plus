#include<bits/stdc++.h>
using namespace std;
void dequy(int n,string s){
	if(n==0) cout<<s<<" ";
	else{
		for(int i=0;i<=1;i++){
			dequy(n-1,s+char(i+'0'));
		}
	}
}
int main(){
	int n;
	cin>>n;
	dequy(n," ");
}

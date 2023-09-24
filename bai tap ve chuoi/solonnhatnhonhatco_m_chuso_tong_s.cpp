#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,s;cin>>m>>s;
	if(s>9*m|| (s==0 &&m>1)){
		cout<<"-1 -1\n"<<endl;
		return 0;
	}
	int lon[m]={0},be[m]={0};
	int tmp=s;
	for(int i=0;i<m;i++){
		if(s>=9){
			lon[i]=9;s-=9;
		}else if(s!=0){
			lon[i]=s;s=0;
		}else break;
	}
	--tmp;
	for(int i=m-1;i>0;i--){
		if(tmp>=9){
			be[i]=9;tmp -=9;
		}else if(tmp!=0){
			be[i]=tmp;tmp=0;
		}else break;
	}
	be[0]=tmp+1;
	for(int i=0;i<m;i++){
		cout<<be[i];
	}
	cout<<" ";
	for(int i=0;i<m;i++){
		cout<<lon[i];
	}
}

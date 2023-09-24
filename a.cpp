// chuong trinh tim uoc chung lon nhat cua 2 so
#include<bits/stdc++.h>
using namespace std;
int checknt(int a){
	for(int i=2;i<sqrt(a);i++){
		if(a%i==0) return 0;
	}
	return 1;
}
long long ucln(int a,int b){
	if(checknt(a)&&checknt(b)) return 1;
	else{
		if(a==0) return b;
		else if(b==0) return a;
		else if(a%b==0) return b;
		else if(b%a==0) return a;
		else if(a>b) return ucln(a,a%b);
		else if(a<b) return ucln(b,b%a); 
	}
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<ucln(n,m);
}

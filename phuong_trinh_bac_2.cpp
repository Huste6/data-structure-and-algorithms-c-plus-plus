#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;cin>>a>>b>>c;
	if(a==0){
		cout<<fixed <<setprecision(2) <<double(-c/b)<< endl;
	}else{
		long long denta=b*b-4*a*c;
		if(denta==0){
			cout<<fixed <<setprecision(2) <<double(-b/(2*a))<< endl;
		}else if(denta<0){
			cout<<"NO SOLUTION";
		}else{
			cout<<fixed <<setprecision(2) <<double((-b-sqrt(denta))/(2*a))<<" "<<double((-b+sqrt(denta))/(2*a))<<endl;
		}
	}
	return 0;
}

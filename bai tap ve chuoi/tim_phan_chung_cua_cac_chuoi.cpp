#include<bits/stdc++.h>
using namespace std;
//ham tim phan tu chung giua 2 chuoi
string common(string s1,string s2){
	string result;
	int n1=s1.length(),n2=s2.length();
	for(int i=0,j=0;i<n1,j<n2;i++,j++){
		if(s1[i]!=s2[j]) break;
		result.push_back(s1[i]);
	}
	return result;
}
//{“geeksforgeeks”, “geeks”, “geek”, “geezer”}
// phan chung: gee

string phanchung(string a[],int l,int r){
	if(l==r){
		return a[l];
	}
	if(l<r){
		int m=(l+r)/2;
		string s1=phanchung(a,l,m);
		string s2=phanchung(a,m+1,r);
		return common(s1,s2);
	}
}
int main(){
	string a[]={"geeksforgeeks", "geeks","geek", "geezer"};
	int n=sizeof(a)/sizeof(a[0]);
	string ans=phanchung(a,0,n-1);
	if(ans.length()){
		cout<<"The longest common prefix is "<< ans;
	}else{
		cout<<"There is no common prefix";
	}
	return 0;
}

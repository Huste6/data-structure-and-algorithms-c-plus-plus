#include<bits/stdc++.h>
using namespace std;
void replace(string& str,char replace_what,char replace_with){
	for(int i=0;str[i]!='\0';i++){
		if(str[i]==replace_what){
			str[i]=replace_with;
		}
	}
}
int main(){
	string s;cin>>s;
	char replace_what,replace_with;
	cin>>replace_what>>replace_with;
	replace(s,replace_what,replace_with);
	cout<<s;
}

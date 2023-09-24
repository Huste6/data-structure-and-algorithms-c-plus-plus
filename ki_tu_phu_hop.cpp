#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char,char> mp;
    mp['{']='}';
    mp['[']=']';
    mp['(']=')';
    stack<char> st;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }else{
            if(st.empty()){
                cout<<"0\n";
                return 0;
            }
            char x=st.top();
            st.pop();
            if(s[i]!=mp[x]){
                cout<<"0\n";
                return 0;
            }
        }
    }
    if(!st.empty()){
        cout<<"0\n";
        return 0;
    }
    cout<<"1\n";
    return 0;
}

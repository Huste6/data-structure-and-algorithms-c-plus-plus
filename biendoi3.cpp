#include <iostream>
#include <string>
using namespace std;

bool check(string s){
    for(int i=0;i<s.length()-1;i++){
        for(int j=i+1;j<s.length();j++){
            if(s[i] == s[j]) return false;
        }
    }
    return true;
}

void dequy(int n,string s){
    if(n==0){
        if(check(s)) cout<<s<<" ";
    }
    else{
        int m=n;
        for(int i=1;i<=m;i++){
            if(s.find(char(i+'0')) == string::npos) // ki?m tra xem i dã xu?t hi?n trong chu?i s chua
                dequy(n-1,s+char(i+'0'));
        } 
    }
}

int main(){
    int n;
    cout<<"Nhap n: "; cin>>n;
    dequy(n," ");
    return 0;
}


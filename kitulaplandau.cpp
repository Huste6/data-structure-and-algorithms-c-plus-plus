#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    set<char> se;
    for(int i = 0; i < s.length(); i++){
        if(se.find(s[i]) != se.end()){
            se.erase(s[i]);
        } else {
            se.insert(s[i]);
        }
    }
    for(int i = 0; i < s.length(); i++){
        if(se.find(s[i]) != se.end()){
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << "All characters are repeated" << endl;
    return 0;
}

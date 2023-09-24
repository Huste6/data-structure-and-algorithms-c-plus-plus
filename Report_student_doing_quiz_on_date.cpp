
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    unordered_map<string,int> mp;
    unordered_set<string> dates;

    while(getline(cin,s)){
        if(s=="*") break;
        string date,time,user_id,question_id;
        stringstream ss(s);
        ss>>date>>time>>user_id>>question_id;
        date=date.substr(0,10);
        mp[date]++;
    }

    for(auto it:mp){
        dates.insert(it.first);
    }

    for(auto it=dates.begin(); it!=dates.end(); ++it){
        cout<<*it<<" "<<mp[*it]<<endl;
    }

    return 0;
}



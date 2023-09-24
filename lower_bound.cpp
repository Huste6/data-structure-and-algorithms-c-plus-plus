#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    vector<int> b;
    b.clear();
    for(int i=0;i<n;i++){
      b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    int n1;cin>>n1;
    while(n1--){
        vector<int>::iterator low;
        int n2;cin>>n2;
        low=lower_bound(b.begin(),b.end(),n2);
        auto it=find(b.begin(),b.end(),n2);
        if(it==b.end()) cout<<"NO"<<" "<<low-b.begin()+1<<endl;
        else cout<<"YES"<<" "<<low-b.begin()+1<<endl;
    }
    return 0;
}


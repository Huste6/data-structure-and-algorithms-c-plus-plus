#include<bits/stdc++.h>
using namespace std;
vector<int> phantichthuasont(int n){
    vector<int> result;
    result.push_back(1);
    while(n%2==0){
        result.push_back(2);
        n=n/2;
    }
    for(int i=3;i*i<=n;i++){
        while(n%i==0){
            result.push_back(i);
            n=n/i;
        }
    }
    if(n>1){
        result.push_back(n);
    }
    return result;
}

int main(){
    int x,y,k;cin>>x>>y>>k;
    vector<int> result1=phantichthuasont(x);
    vector<int> result2=phantichthuasont(y);
    int a[10];
    int l=0;
    for(int i=0;i<result1.size();i++){
        for(int j=0;j<result2.size();j++){
            if(result1[i]==result2[j]){
                a[l]=result1[i];
                ++l;
            }
        }
    }
    if(l<k){
        cout<<"-1";
    }else{
        cout<<a[k+1];
    }
    return 0;
}


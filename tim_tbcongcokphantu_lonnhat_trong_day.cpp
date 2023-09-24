#include<bits/stdc++.h> 
using namespace std; 

float tinh_gt_tb(vector<int> nums,int k,float tb){   
    int j;   
    float sum=0;   
    for(int i=0;i<=nums.size()-k;i++){     
        j=i;     
        while(j<i+k){       
            sum+=nums[j];       
            j++;
        }     
        sum=sum/k;     
        if(tb<sum) 
            tb=sum;     
        sum=0;   
    }   
    return tb; 
} 

int main(){   
    string s;   
    getline(cin,s);   
    vector<int> nums;   
    stringstream ss(s);   
    int number;   
    while(ss>>number){     
        nums.push_back(number);   
    }   
    int k;   
    cin>>k;   
    float tb=0;   
    cout<<fixed<<setprecision(5)<<tinh_gt_tb(nums,k,tb);   
    return 0; 
}



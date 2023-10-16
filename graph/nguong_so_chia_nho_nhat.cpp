#include<bits/stdc++.h>
using namespace std;
int thresold;
bool check(int n, vector<int>& nums) {
    double sum = 0;
    for (double x : nums) {
        sum = ceil(sum);
        sum += x / n;
    }
    return sum <= thresold;
}
int smallestDivisor(vector<int>& nums, double limit) {
    int l = 1, r = pow(10, 6);
    while (l < r) {
        int m = l + (r - l) / 2;
        double sum=0;
        for(auto x:nums){
          sum=ceil(sum);
          sum+=x/m;
        }
        if(sum<=limit) r=m-1;
        else l=m+1;
    }
    return l;
}

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> nums;
    while (ss >> num) {
        nums.push_back(num);
    }
    cin >> thresold;
    sort(nums.begin(), nums.end());
    cout << smallestDivisor(nums, thresold);
    return 0;
}

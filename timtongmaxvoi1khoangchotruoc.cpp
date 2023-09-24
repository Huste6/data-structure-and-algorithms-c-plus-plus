#include<bits/stdc++.h>
#include <vector>
#include <numeric>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int maxSum = 0, sum1 = 0, maxIndex = 0;
    int n = nums.size();
    
    for (int i = 0; i < k; i++) {
        sum1 += nums[i];
    }
    
    maxSum = sum1;
    
    for (int i = k; i < n; i++) {
        sum1 = sum1 - nums[i - k] + nums[i];
        
        if (maxSum < sum1) {
            maxSum = sum1;
            maxIndex = i - k + 1;
        }
    }
    
    vector<int> result(nums.begin() + maxIndex, nums.begin() + maxIndex + k);
    double avg = accumulate(result.begin(), result.end(), 0) / static_cast<double>(k);
    
    return avg;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 5, 2, 7, 8, 9, 1};
    cout << findMaxAverage(nums, 3);
    return 0;
}

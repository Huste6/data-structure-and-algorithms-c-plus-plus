
#include <bits/stdc++.h>
using namespace std;

int longestsubarray(vector<int>& nums, int limit) {
    deque<int> increasing;
    deque<int> decreasing;
    int left = 0, ans = 0;
    for(int right = 0; right < nums.size(); right++) {
        while(!increasing.empty() && increasing.back() > nums[right]) {
            increasing.pop_back();
        }
        while(!decreasing.empty() && decreasing.back() < nums[right]) {
            decreasing.pop_back();
        }
        increasing.push_back(nums[right]);
        decreasing.push_back(nums[right]);
        while(decreasing.front() - increasing.front() > limit) {
            if(nums[left] == decreasing.front()) {
                decreasing.pop_front();
            }
            if(nums[left] == increasing.front()) {
                increasing.pop_front();
            }
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main() {
    vector<int> nums = {12, 3, 4, 6, 9, 1};
    cout << longestsubarray(nums, 7);
    return 0;
}



//tim maxsum cua 1 mang lien tiep

#include <vector>
#include <algorithm>
//tim mang con lien tiep
class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(currentSum, maxSum);
        }
        return maxSum;
    }
};



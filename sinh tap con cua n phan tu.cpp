#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& curr, int i, vector<vector<int>>& ans, vector<int>& nums) {
    if (i > nums.size()) {
        return;
    }

    ans.push_back(curr);
    for (int j = i; j < nums.size(); j++) {
        curr.push_back(nums[j]);
        backtrack(curr, j + 1, ans, nums);
        curr.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    backtrack(curr, 0, ans, nums);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3,4,5,6,7};
    vector<vector<int>> result = subsets(nums);

    // Print the subsets
    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

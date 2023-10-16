#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateSubsetSums(vector<int>& subsets, const vector<int>& arr, int start, int end, int sum) {
    if (start > end) {
        subsets.push_back(sum);
        return;
    }

    // Include the current element
    generateSubsetSums(subsets, arr, start + 1, end, sum + arr[start]);

    // Exclude the current element
    generateSubsetSums(subsets, arr, start + 1, end, sum);
}

bool hasSubsetSum(const vector<int>& arr, int targetSum) {
    int n = arr.size();
    int mid = n / 2;

    // Generate all subset sums for the first half of the array
    vector<int> firstHalfSubsets;
    generateSubsetSums(firstHalfSubsets, arr, 0, mid - 1, 0);

    // Generate all subset sums for the second half of the array
    vector<int> secondHalfSubsets;
    generateSubsetSums(secondHalfSubsets, arr, mid, n - 1, 0);

    // Sort the subset sums for efficient comparison
    sort(secondHalfSubsets.begin(), secondHalfSubsets.end());

    // Check if there exists a subset sum in the first half
    // that can be combined with a subset sum from the second half to form the target sum
    for (int sum : firstHalfSubsets) {
        int complement = targetSum - sum;
        if (binary_search(secondHalfSubsets.begin(), secondHalfSubsets.end(), complement)) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> arr = {1, 5, 11, 5}; // Example array
    int targetSum = 20; // Example target sum

    if (hasSubsetSum(arr, targetSum)) {
        cout << "Subset with the target sum exists." << endl;
    } else {
        cout << "Subset with the target sum does not exist." << endl;
    }

    return 0;
}

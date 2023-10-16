class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = int(matrix.size());
        int n = int(matrix[0].size());
        int left = 0;
        int right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            int num = matrix[row][col];
            
            if (num == target) {
                return true;
            }
            
            if (num < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};

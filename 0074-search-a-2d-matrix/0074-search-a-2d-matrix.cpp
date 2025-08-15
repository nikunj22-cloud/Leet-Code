class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        int left = 0;
        int right = rows * columns - 1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / columns][mid % columns]; // Convert 1D index back to 2D indices
            
            if(midValue == target) {
                return true;
            } else if(midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if(matrix.empty() || matrix[0].empty()) return false;
        
        int n = matrix.size();
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = row*col-1;
        while( left <= right){
            int mid = left + (right-left)/2;
            if( matrix[mid/col][mid%col] == target){ //1 d arr k mid 2d arr k mid seint n = matrix.size();
                return true;
            }
            else if( matrix[mid/col][mid%col] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return false;
    }
};
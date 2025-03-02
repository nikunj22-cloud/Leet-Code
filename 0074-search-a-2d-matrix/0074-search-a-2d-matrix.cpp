class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int r = 0;
        int c = cols-1;
        if(matrix.empty() || matrix[0].empty()){
            return false;
        } //traverse from top right corner because agr target right se bda hua toh mtlb agli row m hoga asending order m h or agr chota hua toh left m hoga
        while(r< rows && c >= 0 ){
              if(matrix[r][c]==target){
                return true;
              }
              else if(matrix[r][c]  > target){
                c--;
              }
              else{
                r++;
              }
              
        }
      return false;  
    }
};
// It is the pivot point where we can decide to move left or down:
// Left: Elements get smaller.
// Down: Elements get larger.
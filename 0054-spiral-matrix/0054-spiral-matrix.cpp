class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;
        vector<int>result;
        while( top <= down && left <= right){
        for( int i = left ; i<= right ; i++){
              result.push_back(matrix[top][i]);
        }
              top++; // 3 to 6
        
        for( int i = top ; i <= down ; i++){
            result.push_back(matrix[i][right]);
        }
            right--;//9 to 8
         
            if (top <= down) {
        for( int i = right ; i >= left ; i--){
            result.push_back(matrix[down][i]);
        }
            down--;//7 to 4
            }
        
         if (right >= left) {
        for( int i = down ; i >= top ; i-- ){
            result.push_back(matrix[i][left]);
        }
            left++; //4 to 5 in qus
        }
    }
    return result;
    }
};
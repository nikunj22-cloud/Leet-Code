class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = n-1;
        int top = 0;
        int down = m-1;
       vector<int>result;
        while( left <= right && top <= down){
            for( int i = left ; i<= right ; i++){
                result.push_back(matrix[top][i]);
            }
                top++;
            
            for( int i = top ; i<= down ; i++){
                result.push_back( matrix[i][right]);
            }
            right--;

            if( down >= top){
             for( int i =  right ; i>= left ; i--){
                result.push_back(matrix[down][i]);
             }
             down--;
            }
            if( left <= right){
                for( int i = down ; i >= top ; i--){
                    result.push_back( matrix[i][left]);
                }
                left++;
            }

        }
        return result;
    }
};
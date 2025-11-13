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
                result.push_back( matrix[top][i]);
              }
              top++; // 3-6
              for( int j = top ; j<= down ; j++){
                result.push_back( matrix[j][right]);
              }
              right--; // 9-8

              if( down >= top){
              for( int i = right ; i >= left ; i-- ){
                result.push_back( matrix[down][i]);
              }
              down--;
              }
              if( right>= left){
              for( int j = down ; j >= top ; j--){
                result.push_back( matrix[j][left]);
              }
              left++;
           }
         }
         return result;
    }
};
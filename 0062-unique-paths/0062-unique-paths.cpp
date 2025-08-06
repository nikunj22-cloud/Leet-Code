class Solution {
public: 
        int t[101][101];
   int unique( int m , int n , int i , int j){
      if( i> m || i<0 || j>n || j<0){
        return 0;
      }
      if( i==m-1 && j == n-1){
        return 1;
      }
       if( t[i][j] != -1){
        return t[i][j];
       }
      
      int down = unique( m , n , i+1 , j); //dowm
     int right =  unique( m , n , i , j+1); //forward

        return t[i][j] = down + right ;
   }
    int uniquePaths(int m, int n) {
          memset( t , -1 , sizeof(t));
      
        return unique( m ,n , 0 , 0);
    }
};
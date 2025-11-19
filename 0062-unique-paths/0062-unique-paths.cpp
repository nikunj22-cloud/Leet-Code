class Solution {
public:  
     int t[101][101];
     int path( int m , int n , int i , int j){
        if( i < 0 || i > m || j < 0 || j > n ){
            return 0;
        }
         if( t[i][j] != -1){
            return t[i][j];
         }
        if( i == m-1 && j == n-1){
            return 1;
        }
         int down = path( m , n ,i+1 , j );
         int right = path( m , n , i , j+1);
         return  t[i][j] = down+right;
     }
    int uniquePaths(int m, int n) {
         memset( t , -1 , sizeof(t));
         return path( m , n , 0 ,0);
    }
};
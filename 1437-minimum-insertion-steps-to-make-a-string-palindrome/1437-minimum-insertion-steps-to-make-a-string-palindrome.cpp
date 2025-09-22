class Solution {
public: 
    int t[501][501];
    int minin( string &s , int i , int j){
        if( i>= j){
            return 0;
        }
        if( t[i][j] != -1){
            return t[i][j];
        }
        if( s[i] == s[j]){
            return t[i][j] = minin( s , i+1 , j-1);
        }
        return t[i][j] = 1 + min(minin(s , i+1 , j) , minin(s , i ,j-1));
    }
    int minInsertions(string s) {
        int n = s.length();
         memset( t , -1 , sizeof(t));
         return minin( s , 0 ,n-1);
        
    }
};
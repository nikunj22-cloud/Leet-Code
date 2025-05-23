class Solution {
public:
 int  t[1001][1001];
     bool palindrom( string& s , int i ,int j){
        if( i >= j){
            return 1;
        }
          if(t[i][j] != -1){
            return t[i][j];
          }
        if( s[j]== s[i]){
            return  t[i][j] = palindrom( s , i+1 , j-1);
        }
        return t[i][j] = 0;
     }
    string longestPalindrome(string s) {
           int n = s.length();
          memset( t , -1 , sizeof(t));
        int maxsize = INT_MIN;
        int stpoint = 0;
       
       
        for( int i = 0 ; i<n ; i++){
           for( int j = i ; j< n ; j++){
             if(palindrom(s , i , j)==true){
                if( j-i+1 > maxsize){
                    maxsize = j-i+1;
                stpoint =  i;
                }
             }
           }
        }
        return s.substr( stpoint , maxsize);
    }
};
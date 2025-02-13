class Solution {
public:
    string countAndSay(int n) {
       if( n==1) return "1";  //question main diya hua h

       string say = countAndSay( n-1); //question m diya hua h
       string result = "";

       for( int i = 0 ; i < say.length() ; i++){
          char ch = say[i];
          int count = 1;

          while( i< say.length()-1 && say[i]==say[i+1]){
            i++;
            count++;
          }
          result += to_string(count) + string( 1 , say[i]); 
       }
       return result;

    }
};
class Solution {
public:
    int myAtoi(string s) {
       int i = 0;
       long num =0;
       int sign  =1;
       int n = s.size();
       //step1 ignore white space
       while( i< n && s[i]==' '){
        i++;
       }   
       //step2 handle sign
      if( i< n  &&( s[i]=='+' || s[i]=='-')){
        sign = (s[i] =='+') ? 1 : -1 ;
        i++;
      }
      //convert to integer
      while( i< n && isdigit(s[i])){
        num = num * 10 + (s[i] - '0');

        //check the limit exceed
        if( num*sign > INT_MAX)return INT_MAX;
        if( num*sign < INT_MIN) return INT_MIN;

        i++;

      }
      return num*sign;
    }
};
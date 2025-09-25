class Solution {
public:
    string countAndSay(int n) {
        if( n == 1){
            return "1";
        }
        string result  = "";
        string say = countAndSay(n-1);
        for( int i = 0  ; i< say.length() ; i++){
            char ch = say[i];
            int count = 1;
           while( i< say.length()-1 && say[i] == say[i+1]){
                 count++;
                 i++;
           }
           result += to_string(count) + string( 1 , ch); //char ko string m bdlne ka tarika 
        }
        return result;
    } 
};
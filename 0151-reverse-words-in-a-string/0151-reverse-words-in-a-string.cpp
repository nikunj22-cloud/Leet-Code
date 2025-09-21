class Solution {
public:
    string reverseWords(string s) {
        // 3 steps
        //reverse word
        //reverse character of the word
        //add space in the  beginnning of the word when you adjust word in correct order 
        string ans = "";
       
        int n = s.length();
        reverse( s.begin() , s.end());
        for( int i = 0 ; i< n ; i++){
             string word = "";
              while( i < n && s[i] != ' '){
                word += s[i];
                   i++;
              }
              reverse(word.begin() , word.end());
              if( word.length() > 0){
                ans += " " + word;
              }
        }
        return ans.substr(1);

    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
       string first = strs[0];
       int n = strs.size();
        string last = strs[n-1];
       string result = "";//output khali b aa skta h without space remember
    
     for( int i = 0 ; i<first.size() ; i++){
         if(first[i] != last[i])break;
         result += first[i];
     }   
     return result;
    }
};
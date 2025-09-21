class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
          sort( strs.begin() , strs.end());
          string result = "";
          int n = strs.size();
          string first = strs[0];
           string last = strs[n-1];
         for( int i = 0 ; i< first.size() ; i++){ //remember first.size tk chlega bss or toh halua h
                 if(first[i] != last[i])break;
         result += first[i];
         }
         return result;
    }
};
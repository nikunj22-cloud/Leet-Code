class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l = 0;
       int maxlenght = 0 ;
       unordered_set<int>st;
       for( int r = 0 ; r<s.length() ; r++){
        while(st.find(s[r])!= st.end()){
            st.erase(s[l]);
            l++;
        }
        st.insert(s[r]);
        maxlenght = max(maxlenght , r-l+1);
       }   
     return maxlenght;
    }
};
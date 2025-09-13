class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int left = 0;
         int maxlen = 0;
        for( int right = 0 ; right < s.length(); right++){
            while( st.find(s[right]) != st.end()){
                st.erase( s[left]);
                left++;
                maxlen = max( maxlen , right-left+1);
            }
            st.insert(s[right]);
        } 
        return maxlen;
    }
};
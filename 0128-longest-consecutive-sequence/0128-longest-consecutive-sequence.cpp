class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st( nums.begin() , nums.end());
        //set k ander unique set dalne ka tarika 
        int ans = 0;
        for( int i = 0 ; i<nums.size() ; i++){
            if( st.find(nums[i]) != st.end()){
                st.erase( nums[i]);
            }
            int next = nums[i]+1;
            int prev = nums[i]-1;

            while( st.find(next) != st.end()){
                st.erase(next);
                next++;
            }
            while( st.find(prev) != st.end()){
                st.erase(prev);
                prev--;
            }
            ans = max( ans , next-prev-1);
        }
    return ans;
    }
};
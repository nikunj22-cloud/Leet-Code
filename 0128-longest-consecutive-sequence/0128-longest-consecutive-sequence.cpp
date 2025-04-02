class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end()); // Step 1: Insert all elements in set
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) { // Step 2: Use normal for loop
            if (st.find(nums[i] - 1) == st.end()) { // Check if nums[i] is the start of a sequence
                int seq = nums[i];
                int count = 1;

                while (st.find(seq + 1) != st.end()) { // Continue sequence
                    seq++;
                    count++;
                }

                ans = max(ans, count); // Update max sequence length
            }
        }

        return ans;
    }
};
;
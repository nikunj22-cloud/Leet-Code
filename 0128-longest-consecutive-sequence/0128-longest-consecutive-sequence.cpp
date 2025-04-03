class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end()); // Step 1: Insert all elements in set
        int ans = 0;
        
        for (int num : nums) { // Step 2: Use normal for loop
            if (st.find(num) != st.end()) { // If num is still in set
                st.erase(num); // Remove num (avoid re-processing)

                int prev = num - 1, next = num + 1;
                while (st.find(prev) != st.end()) {
                    st.erase(prev);
                    prev--;
                }
                while (st.find(next) != st.end()) {
                    st.erase(next);
                    next++;
                }

                ans = max(ans, next - prev - 1); // Update max length
            }
        }

        return ans;
    }
};


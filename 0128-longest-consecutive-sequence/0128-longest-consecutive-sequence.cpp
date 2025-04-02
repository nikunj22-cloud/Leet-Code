class Solution {
public: //yeh pura code yad rkhna pdega kyoki yeh time limit ka error de rha h so yad rko
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end()); // Insert all elements into the set
        int ans = 0;

        for (int num : st) { // Iterate through the set, not the vector
            // Check if the current number is the start of a sequence
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int count = 1;

                // Count the length of the sequence
                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    count++;
                }

                // Update the maximum length
                ans = max(ans, count);
            }
        }

        return ans;
    }
};
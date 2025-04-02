class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Edge case: empty array

        sort(nums.begin(), nums.end()); // Step 1: Sort the array (O(N logN))

        int ans = 1, count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue; // Skip duplicate elements
            
            if (nums[i] == nums[i - 1] + 1) {
                count++; // Increase sequence length
            } else {
                ans = max(ans, count); // Update max sequence length
                count = 1; // Reset count for new sequence
            }
        }

        return max(ans, count); // Return max sequence length
    }
};

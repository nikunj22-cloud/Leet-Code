class Solution {
public: 
    vector<vector<int>> ans;
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Step 1: Sort the array
        int n = nums.size();

        for (int first = 0; first < n - 3; first++) {
            // Skip duplicates for first pointer
            if (first > 0 && nums[first] == nums[first - 1]) continue;

            for (int second = first + 1; second < n - 2; second++) {
                // Skip duplicates for second pointer
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;

                int third = second + 1;
                int forth = n - 1;

                while (third < forth) {
                    long long sum = (long long)nums[first] + (long long)nums[second] + 
                                    (long long)nums[third] + (long long)nums[forth];

                    if (sum > target) {
                        forth--;  // ✅ Decrease forth pointer
                    } else if (sum < target) {
                        third++;  // ✅ Increase third pointer
                    } else {
                        ans.push_back({ nums[first], nums[second], nums[third], nums[forth] });

                        third++;
                        forth--;

                        // Skip duplicate values for `third`
                        while (third < forth && nums[third] == nums[third - 1]) third++;

                        // Skip duplicate values for `forth`
                        while (third < forth && nums[forth] == nums[forth + 1]) forth--;
                    }
                }
            }
        }

        return ans;
    }
};

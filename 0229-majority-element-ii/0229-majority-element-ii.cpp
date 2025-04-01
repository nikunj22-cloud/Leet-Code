class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj1 = INT_MIN, count1 = 0;
        int maj2 = INT_MIN, count2 = 0;

        // First pass: Find potential candidates
        for (int num : nums) {
            if (num == maj1) {
                count1++;
            } else if (num == maj2) {
                count2++;
            } else if (count1 == 0) {
                maj1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                maj2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Second pass: Verify counts
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == maj1) count1++;
            else if (num == maj2) count2++;
        }

        vector<int> result;
        if (count1 > n / 3) result.push_back(maj1);
        if (count2 > n / 3) result.push_back(maj2);

        return result;
    }
};

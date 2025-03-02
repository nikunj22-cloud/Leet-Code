class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1 = 0, maj2 = 0, count1 = 0, count2 = 0;
        
        // Step 1: Finding potential majority candidates
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
        
        // Step 2: Verifying the candidates freq
        int f1 = 0, f2 = 0;
        for (int num : nums) {
            if (num == maj1) f1++;
            if (num == maj2) f2++;
        }
        
        vector<int> result;
        if (f1 > nums.size() / 3) result.push_back(maj1);
        if (maj1 != maj2 && f2 > nums.size() / 3) result.push_back(maj2); // Avoid duplicate
        
        return result;
    }
};

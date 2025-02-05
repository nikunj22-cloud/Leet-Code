class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        
        for (int num : nums) {
            if (num == 1) {
                count++;  // Consecutive 1s ko count karo
                maxCount = max(maxCount, count);  // Maximum consecutive 1s track karo
            } else {
                count = 0;  // 0 aate hi streak reset ho jayega
            }
        }
        return maxCount;
    }
};

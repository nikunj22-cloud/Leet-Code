class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroIndex = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[lastNonZeroIndex++] = nums[i];
            }
        }

        // Fill the remaining elements with 0
        for (int i = lastNonZeroIndex; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};  
//The zeros are lost, and we don't care — because the second loop will add new zeros at the end.
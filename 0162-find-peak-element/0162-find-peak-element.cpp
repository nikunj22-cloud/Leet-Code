class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases
        if (n == 1) return 0; // Only one element
        if (nums[0] > nums[1]) return 0; // First element is a peak
        if (nums[n - 1] > nums[n - 2]) return n - 1; // Last element is a peak
        
        int low = 1;
        int high = n - 2;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            // Check if mid is a peak
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            // If mid is in an increasing slope, peak is on the right
            else if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            }
            // If mid is in a decreasing slope, peak is on the left
            else {
                high = mid - 1;
            }
        }
        
        // This return statement is unreachable but added for completeness
        return -1;
    }
};
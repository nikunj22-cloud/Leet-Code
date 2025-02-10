class Solution {
public:
    // Function to find the leftmost (first) occurrence of the target
    int findLeftMost(int target, int n, vector<int>& nums) {
        int left = 0, right = n - 1;
        int leftMost = -1; // Initialize to -1 (not found)
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                leftMost = mid; // Update leftMost
                right = mid - 1; // Search in the left half
            } else if (nums[mid] < target) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        return leftMost;
    }

    // Function to find the rightmost (last) occurrence of the target
    int findRightMost(int target, int n, vector<int>& nums) {
        int left = 0, right = n - 1;
        int rightMost = -1; // Initialize to -1 (not found)
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                rightMost = mid; // Update rightMost
                left = mid + 1; // Search in the right half
            } else if (nums[mid] < target) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        return rightMost;
    }

    // Main function to find the range of the target
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int leftMost = findLeftMost(target, n, nums); // Find the leftmost index
        int rightMost = findRightMost(target, n, nums); // Find the rightmost index
        return {leftMost, rightMost}; // Return the result as a vector
    }
};
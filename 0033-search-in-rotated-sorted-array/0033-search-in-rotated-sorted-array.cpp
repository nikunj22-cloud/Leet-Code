class Solution {
public:
    // Function to find the pivot (smallest element) in the rotated sorted array
    int pivot_element(vector<int>& nums, int n) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1; // Pivot is in the right half
            } else {
                r = mid; // Pivot is in the left half
            }
        } 
        return l; // Return the index of the smallest element becasuse it is design to find lowest element
    }

    // Standard binary search function
    int binarySearch(int l, int r, int target, vector<int>& nums) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] > target) {
                r = mid - 1; // Search in the left half
            } else {
                l = mid + 1; // Search in the right half
            }
        }
        return -1; // Target not found
    }

    // Main search function
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1; // Edge case: empty array

        // Find the pivot index
        int pivot = pivot_element(nums, n);

        // If the target is the pivot element
        if (nums[pivot] == target) {
            return pivot;
        }

        // Decide which part of the array to search
        if (pivot == 0) {
            // Array is not rotated, search the entire array
            return binarySearch(0, n - 1, target, nums);
        } else if (target >= nums[0] && target <= nums[pivot - 1]) {
            // Target is in the left sorted part
            return binarySearch(0, pivot - 1, target, nums);
        } else {
            // Target is in the right sorted part
            return binarySearch(pivot, n - 1, target, nums);
        }
    }
};
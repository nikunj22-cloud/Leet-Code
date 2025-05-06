class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int N = n1 + n2;
        int start = 0, end = n1;

        while (start <= end) {
            int cut1 = start + (end - start) / 2;
            int cut2 = N / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if (N % 2 != 0) {
                    return min(r1, r2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } else if (l1 > r2) {
                end = cut1 - 1;
            } else {
                start = cut1 + 1;
            }
        }

        return 0.0; // should not reach here
    }
};
//Why min(n, m)?

// Because we always apply binary search on the shorter array to avoid index errors and minimize steps.
///The left parts of both arrays contain the correct number of elements (i.e., cut1 + cut2 = total/2)
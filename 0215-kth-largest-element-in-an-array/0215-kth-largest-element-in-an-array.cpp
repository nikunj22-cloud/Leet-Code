class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>>pq;
        for( int i = 0 ; i<nums.size() ; i++){
            pq.push(nums[i]);
            if( pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
//nums = [3, 2, 1, 5, 6, 4]
// k = 2   // matlab 2nd largest element chahiye
// Step by step dry run
// Heap banaya hai:

// cpp
// Copy code
// priority_queue<int, vector<int>, greater<int>> pq;
// \U0001f449 Ye ek min heap hai (top = sabse chhota element).

// Iteration 1:
// Push 3

// Heap = [3]
// (size = 1 ≤ k, ok)

// Iteration 2:
// Push 2

// Heap = [2, 3] (min heap me top = 2)
// (size = 2 ≤ k, ok)

// Iteration 3:
// Push 1

// Heap = [1, 3, 2]

// Ab size = 3 > k → pop() → remove 1 (smallest)

// Heap = [2, 3]

// Iteration 4:
// Push 5

// Heap = [2, 3, 5]

// Size = 3 > k → pop() → remove 2

// Heap = [3, 5]

// Iteration 5:
// Push 6

// Heap = [3, 5, 6]

// Size = 3 > k → pop() → remove 3

// Heap = [5, 6]

// Iteration 6:
// Push 4

// Heap = [4, 6, 5]

// Size = 3 > k → pop() → remove 4

// Heap = [5, 6]

// Final Heap
// [5, 6]

// Top = 5

// Aur yehi hai kth (2nd) largest element ✅


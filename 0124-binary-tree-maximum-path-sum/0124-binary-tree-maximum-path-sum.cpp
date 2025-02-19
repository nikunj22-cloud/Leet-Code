/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum;  // Store the maximum path sum
    
    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        // Recursively get the max path sum from left and right subtrees
        int l = solve(root->left);
        int r = solve(root->right);

        // Possible cases:
        int neehce_mil_gya = l + r + root->val;  // Including both children
        int koi_ek_acha = max(l, r) + root->val; // Choosing the better child
        int only_root = root->val;               // Only taking the root

        // Update the max sum encountered so far
        maxSum = max({maxSum, neehce_mil_gya, koi_ek_acha, only_root});

        // Return the best sum that can be included in a single path
        return max(koi_ek_acha, only_root);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;  // Initialize with the smallest possible value
        solve(root);
        return maxSum;
    }
};

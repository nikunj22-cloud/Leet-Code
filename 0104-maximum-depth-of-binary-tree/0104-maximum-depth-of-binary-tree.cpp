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
    int Level(TreeNode* root, int level) {
        if (root == nullptr) return level;  // Base case

        int leftDepth = Level(root->left, level + 1);
        int rightDepth = Level(root->right, level + 1);

        return max(leftDepth, rightDepth); // Return max depth
    }

    int maxDepth(TreeNode* root) {
        return Level(root, 0);
    }
};

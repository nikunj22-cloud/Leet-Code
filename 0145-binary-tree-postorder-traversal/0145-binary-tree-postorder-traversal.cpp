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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderHelper(root, result); // Call the helper function
        return result;
    }

private:
    void postorderHelper(TreeNode* node, vector<int>& result) {
        if (!node) return; // Base case: if the node is null, return

        postorderHelper(node->left, result);  // Traverse the left subtree
        postorderHelper(node->right, result); // Traverse the right subtree
        result.push_back(node->val);         // Visit the root node
    }
};
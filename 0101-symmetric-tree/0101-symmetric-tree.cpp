/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL)
            return true;
        if (a == NULL || b == NULL)
            return false;
        return (a->val == b->val) && check(a->left, b->right) &&
               check(a->right, b->left); //condition yad rkhni h yeh ki a->left or b->right then a->right b->left
    }
    bool isSymmetric(TreeNode* root) {
        // If the tree is empty, it is symmetric
        if (root == NULL) {
            return true;
        }
        // Check if the left and right subtrees are mirror images
        return check(root->left, root->right);
    }
};
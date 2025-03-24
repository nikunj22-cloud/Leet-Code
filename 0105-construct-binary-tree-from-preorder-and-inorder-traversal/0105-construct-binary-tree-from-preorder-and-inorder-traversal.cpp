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
    unordered_map<int, int> inorderMap; // To store index of inorder values
    int preorderIndex = 0;

    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (start > end) return NULL; // Base case: no elements left

        int rootVal = preorder[preorderIndex++]; // Pick root from preorder
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = inorderMap[rootVal]; // Find root in inorder

        // Recursively build left and right subtrees
        root->left = create(preorder, inorder, start, inorderIndex - 1);
        root->right = create(preorder, inorder, inorderIndex + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Store inorder indices for O(1) lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return create(preorder, inorder, 0, inorder.size() - 1);
    }
};

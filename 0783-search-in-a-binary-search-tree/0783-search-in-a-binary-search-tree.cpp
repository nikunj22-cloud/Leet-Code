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
    TreeNode* searchBST(TreeNode* root, int val) {
         if(root==NULL)return root;
         if(root->val== val)return root;

         if(root->val < val)
         return searchBST(root->right , val);
         else
         return searchBST(root->left , val);
    }
}; //sub tree roted return krni h toh mtlb recursion hee chlega return m or binary serch tree h toh mtlb value k basic pr hee ans find hoga
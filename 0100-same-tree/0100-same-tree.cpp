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
    bool isSameTree(TreeNode* p, TreeNode* q) {
      
      if(!p && !q)return true; //agr dono h hee nhi toh mtlb ans true h
      if(!p || !q)return false; //agr p h or q nhi toh same kese hoga false 
      if(p->val != q->val)return false; //aree bhai agr p ka root or q ka root same nhi h toh false
      return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);   
    }
};
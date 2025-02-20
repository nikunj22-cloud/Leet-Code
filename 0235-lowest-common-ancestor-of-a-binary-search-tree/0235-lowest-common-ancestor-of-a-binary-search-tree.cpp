/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(root==NULL)return NULL;
         if( root->val == p->val || root->val == q->val)return root;

        TreeNode* l = lowestCommonAncestor( root->left , p ,q);
        TreeNode* r = lowestCommonAncestor(root->right  , p ,q);

        if( l && r) //if l and r dono exist krte h toh p b koi subtree m hoga as well as r b koi si subtree m hoga toh mtlb root ko return kro simple
            return root;
        
        return r?r:l; //if l khali toh l return kro agr nhi h toh r  vice versa l b return krwa skte ho agr khali l h toh
    }
};
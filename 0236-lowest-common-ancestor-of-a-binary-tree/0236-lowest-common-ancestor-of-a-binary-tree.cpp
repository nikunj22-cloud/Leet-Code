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
        if(root == NULL){
            return NULL;
        }
        TreeNode* left = lowestCommonAncestor(root->left , p , q);
        TreeNode*right = lowestCommonAncestor(root->right , p , q);

        if( root == p || root == q){
            return root;
        }
        if(left != NULL && right != NULL){
            return root;
        }
        //Iska Matlab

// Humne lowestCommonAncestor(root->left, p, q) call karke left subtree me search kiya. Agar p ya q left subtree me mil gaya, toh left != NULL hoga.

// Waise hi lowestCommonAncestor(root->right, p, q) se right subtree check kiya. Agar p ya q right subtree me hai, toh right != NULL hoga.

// \U0001f449 Ab agar ek node left me mila aur dusra right me → iska matlab kya hua?

// Dono current root ke alag-alag subtrees me mile.

// Toh root hi unka common ancestor hua.

// Aur kyunki ye condition tabhi true hogi jab dono side se mila hai → ye hi Lowest Common Ancestor bhi hai.
//unka common lowest root hee hoga kyoki dono subtree m se mile h 
        if(left != NULL){
            return left;
        }
        return right;
    }
};
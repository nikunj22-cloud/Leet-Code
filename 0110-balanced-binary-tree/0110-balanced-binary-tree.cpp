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
     int height( TreeNode*root){
        if(root==NULL)return 0 ;
        int leftheight = height(root->left);
        int rightheight = height(root->right); 
        if(leftheight == -1)return -1 ; //means left m toh child hee nhi h
        if(rightheight == -1) return -1; //right m toh child nhi h unbalanced
         if(abs(leftheight - rightheight )> 1) return -1; //because unbalnced h kyoki abs value ya toh 1 pr balance hoga ya 0 pr
         return max(leftheight , rightheight)+1;//yad rkhna ek node khud h 
     }
    bool isBalanced(TreeNode* root) {
         return height(root)!= -1;
        
    }
};
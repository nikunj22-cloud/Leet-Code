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
     TreeNode* BST( vector<int>& preorder , int min , int max , int&  index){
        if(index >= preorder.size())return NULL;
         int val = preorder[index];
         if( val > max || val < min ) return NULL;

         TreeNode* root = new TreeNode(val);
        index++;

         root->left = BST( preorder , min , val , index);
         root->right = BST( preorder  , val , max , index );

         return root;
     }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int index = 0;
        return BST(preorder , INT_MIN ,INT_MAX , index);   
    }
};
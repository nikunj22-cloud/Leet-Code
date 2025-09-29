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
   int search(  vector<int>& inorder , int left , int right ,int val){
    for( int i = left ; i <= right ; i++ ){
        if( inorder[i] == val){
            return i;
        }
    }
   return -1;
}
     TreeNode* helper( vector<int>&preorder , vector<int>&inorder , int left , int right , int& preidx){
         if(  left > right){
            return NULL;
         }
         TreeNode*root = new TreeNode(preorder[preidx]);
          int inidx =   search( inorder ,left  ,right , preorder[preidx] );
           preidx++;
           root->left = helper( preorder , inorder , left , inidx-1 , preidx);
           root->right = helper( preorder , inorder , inidx+1 , right , preidx);
           return root;
           
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int preidx = 0;
        return helper( preorder , inorder , 0 , inorder.size()-1 , preidx );
    }
}; 
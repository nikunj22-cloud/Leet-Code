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
      bool solve(TreeNode* root , long minimum , long maximum){
         if(!root) return true;
          if(root->val <= minimum || root->val >= maximum){
            return false;
          }
        bool leftsubtree = solve(root->left , minimum , root->val);
        bool  rightsubtree = solve(root->right , root->val , maximum);
         return (leftsubtree && rightsubtree) ;
      }
    bool isValidBST(TreeNode* root) {
      return solve(root ,LONG_MIN , LONG_MAX);
     
    }
};
//iss qus m yeh method se solve krna normal h kyoki qus m saaf likha h The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
//Both the left and right subtrees must also be binary search trees. toh phle hmko left subtree ko right subtree ko ek ek krke check krna pdega ki sab true h or false then aage ka pta chlega 
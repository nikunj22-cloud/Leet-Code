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
public: //we use inorder traversal because 1 smallest element will be from left then root then right 
  int count = 0 , result = -1; 
     void inorder( TreeNode* root , int k){
     if(root==NULL|| count >= k)return;
     inorder( root->left , k);
     count++;
     if( count == k){
        result = root->val; //result ko assign krenge return root->val mt krna kyoki function void return krrrha h
        return;
     }
     inorder( root->right , k);


     }
    int kthSmallest(TreeNode* root, int k) {
        inorder( root , k);
         return result; //return result krna root nhi 
    }
};
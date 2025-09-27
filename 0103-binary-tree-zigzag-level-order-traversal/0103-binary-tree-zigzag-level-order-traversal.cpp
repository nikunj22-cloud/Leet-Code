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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector<vector<int>>result;
          queue<TreeNode*>q;
           if(root == NULL) return result;
          q.push(root);
          bool lefttoright = true;
          while( !q.empty()){
             int size = q.size();
             vector<int>ans;
             for(int i = 0 ; i<size ; i++){
                TreeNode*t = q.front();
                q.pop();
             ans.push_back(t->val);
             
             if( t->left){
                q.push(t->left);
             }
             if( t->right){
                q.push(t->right);
             }
             }
             if( !lefttoright){
                reverse(ans.begin() , ans.end());
             }
             lefttoright = !lefttoright;
             result.push_back(ans);
          }
          return result;
    }
};
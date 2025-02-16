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
     void Level( TreeNode* root , int level , vector<vector<int>>&res){
        if(root==nullptr)return ;
        if(res.size() <= level){
            //agr koi res k size se b bda nikl gya h level toh usko res m push krdo
            res.push_back({});
        }
        res[level].push_back(root->val);
        Level( root->left , level+1, res);
        Level(root->right , level+1 , res);

     }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level ;
        vector<vector<int>>res;
        Level( root , 0 , res);
        return res;
    }
};
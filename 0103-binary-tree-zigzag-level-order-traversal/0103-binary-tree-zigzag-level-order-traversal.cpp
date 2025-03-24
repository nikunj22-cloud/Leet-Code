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
        // Agar tree khali hai
        if (root == NULL) return {};
        
        vector<vector<int>> answer;  // Final result ke liye
        queue<TreeNode*> q;          // Level order ke liye queue
        q.push(root);
        bool direction = true;       // True = left to right, False = right to left
        
        while (!q.empty()) {
            int levelSize = q.size();    // Current level ke nodes ki count
            vector<int> level;           // Current level ke values store karne ke liye
            
            // Har node ko process karo current level mein
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Yahan level mein value push kar rahe hain
                level.push_back(node->val); // Node ki value level mein daal do
                
                // Children ko queue mein daal do agle level ke liye
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Agar direction right-to-left hai toh reverse karo
            if (!direction) {
                reverse(level.begin(), level.end());
            }
            
            // Poora level banne ke baad answer mein daal do
            answer.push_back(level);
            direction = !direction;  // Direction flip karo
        }
        
        return answer;
    }
};
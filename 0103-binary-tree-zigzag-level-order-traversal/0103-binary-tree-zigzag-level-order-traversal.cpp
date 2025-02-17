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
       vector<vector<int>> result;
       if (root == NULL) return result;

       queue<TreeNode*> q;
       q.push(root);
       bool leftToRight = true;

       while (!q.empty()) {
           int size = q.size();
           vector<int> ans(size); // Fixed-size vector for storing values at this level

           for (int i = 0; i < size; i++) {
               TreeNode* front = q.front();
               q.pop();

               // Compute index based on zigzag order
               int index = leftToRight ? i : size - i - 1;
               ans[index] = front->val;

               // Push left and right children into queue
               if (front->left) q.push(front->left);
               if (front->right) q.push(front->right);
           }

           // Add the current level's values to result
           result.push_back(ans);
           // Toggle the direction for next level
           leftToRight = !leftToRight;
       }

       return result;
    }
};

// Utility function to print the result
void printZigzagOrder(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

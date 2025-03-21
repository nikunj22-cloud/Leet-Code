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
    //   void inorder( TreeNode* root , vector<int>&result){
    //     if(!root)return;
    //     inorder(root->left , result);
    //     result.push_back(root->val);
    //     inorder(root->right , result);
    //   }
    //using morris inorder
    vector<int> inorderTraversal(TreeNode* root) {
            //  vector<int>result;
            //  inorder(root , result);
            //  return result;
            TreeNode*curr  = root;
            vector<int>result;
            while(curr != NULL){
                if( curr->left == NULL){
                    result.push_back(curr->val);
                    curr = curr->right;
                }
                else{
                    TreeNode*leftChild = curr->left;
                    while(leftChild->right != NULL){
                        leftChild = leftChild->right;
                    }
                    leftChild->right = curr;

                    //ab curr ko aage bdhakrr delete krne ki bari h
                    TreeNode* temp = curr ;
                    curr = curr->left;//yr yeh yad rkhna pdega kyoki yeh dry run krke smz nhi aaya
                    temp->left = NULL;

                }

                 

            }
            return result;
    }
}; //tc o(n)wcase
//sc o(n) wcase

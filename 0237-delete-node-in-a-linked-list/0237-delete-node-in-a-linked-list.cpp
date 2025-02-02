/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      ListNode*prev = NULL;
      while(node->next != NULL){
        node->val = node->next->val;
        prev = node ;//assign prev to node (remember thing)
        node = node->next; //traverse the node to reach null
        
      }
      prev->next = NULL;
      delete(node);
    }
};

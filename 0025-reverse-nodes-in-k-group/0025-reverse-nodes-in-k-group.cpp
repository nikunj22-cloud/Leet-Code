/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */ 
 //step 1 if the k is greater then list return null
 //reverse rest of the linked list
 //reverse the curr list
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        int count  = 0;
        while(  count < k && temp!= NULL){
            
            temp = temp->next;
            count++;
        }
        if (count < k) return head; // Not enough nodes to reverse
       ListNode* prev = reverseKGroup( temp , k); //remmber temp dala jayega because temp ko traverse krrhe h
                temp = head;
                 count = 0;
       ListNode * next = NULL;

       while( count< k){
         next = temp->next;
         temp->next =  prev;
         prev = temp;
         temp = next;
         count++;
       }
       return prev;//yeh toh yad rkhle bhai 
    }
};
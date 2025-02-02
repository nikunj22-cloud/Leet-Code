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
class Solution {
public:
   int getLengthOfLinkedList(ListNode* head){
    int length = 0;
    while(head!= NULL){
        head = head->next;
        length++;
    }
    return length;

   }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L = getLengthOfLinkedList(head);
        if( n== L){
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }
        int traverse = L-n;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(traverse--){
              prev = temp;
              temp = temp->next;         
        }
        prev->next = temp->next;
        delete(temp);
        return head;
    }
};
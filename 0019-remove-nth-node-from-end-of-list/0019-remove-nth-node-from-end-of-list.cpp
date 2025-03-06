/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */  //constraints no 3 says ki n ki value kbhi b jyada ni hogi size se
class Solution {
public:
     int getLength( ListNode* head ){
        int length = 0;
        while( head!= NULL){
            head = head->next;
            length++;
        }
        return length;

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L = getLength(head);
        if(n== L){
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }
        int traverse = L-n;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(traverse--){
            prev = temp ;
            temp = temp->next ;
        }
        prev->next = temp->next;
        delete(temp);
        return head;  
    }
};
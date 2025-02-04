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
  ListNode *findNnode( ListNode *temp , int k ){
    int count = 1;
    while(temp != NULL) {
        
        if( count == k)return temp;
        temp = temp->next;
        count++;
    }
    return temp;
  }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail = head;
        int len = 1;
        if(head==NULL || k==0) return head; //edge cases
        while( tail->next != NULL){
            tail = tail->next;
            len += 1;
        }
        if(k % len == 0  ) return head ; //agr k len k multiple m h toh khali head return krdo 
         k = k % len ; //k joh h len se bda h
         tail->next = head ; //mtlb tail null mil gya h toh tail ko agle head se jod do

        ListNode *newLastNode = findNnode( head , len-k) ;
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
  //agr cycle nhi hogi toh yeh null hee honge obviousoly
 //joh pointer tej chlrha h uski conditon likhni pdegi
 //mtlb cycle exist krti h so break krdo kyoki hmko toh start point return krn h
 //loop se bahar nikl gye or fast or slow barabar ni aaye kya mtlb h iska cycle nhi h toh null return krdo
  //ab agr loop ya cycle h toh start point pta krna h uske liye ek pointer le lo
  //ab condition check krenge ki slow or p kha pr match krrhe h or wha pr undono m se kisi b node ko retun krdenge
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next == NULL)return NULL;

        ListNode *slow = head;
        ListNode *fast = head;
        while( fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if( fast == slow) break ;
              
        }
        if( slow != fast){
          return NULL;
        }
        ListNode *p = head;
        while( p != slow){
            p = p->next;
            slow = slow->next;
        }
        return p;
    }
};
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode *first = headA;
       ListNode *second = headB;

       while( first != second){
        first = (first==NULL)? headA : first->next;
        second = (second==NULL)? headB : second->next;//yeh yad rkhle bhai agr nhi smz aara toh ki null hote hi reset ki condition lgegi
       }
       return first;
    } 
};
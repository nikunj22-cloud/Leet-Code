/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */ //time complexity o(m+n)
 //space 0(1)
//  . If the two linked lists have no intersection at all, return null.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while (ptrA != ptrB) {
           ptrA = (ptrA == NULL) ? headB : ptrA->next;
           ptrB = (ptrB == NULL) ? headA : ptrB->next;

        }

        return ptrA; // can be NULL (no intersection) or the intersection node
    }
};

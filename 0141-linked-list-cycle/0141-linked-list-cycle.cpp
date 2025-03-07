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
    bool hasCycle(ListNode *head) {
        map<ListNode* , bool>visited; //map bnaya jisme node ko or detect k liye bool flag ko store kiya
        ListNode*temp = head; //for traversing
        while(temp!=NULL){
            if(visited[temp]== true){
                return true; //mtlb phle se hee cycle presnet h 
            }
            visited[temp] = true; //traverse krte tym true krte chlo jisse pta lgta rhe ki cycle h ya ni 
            temp = temp->next; //normal traversing in loop
             
        }
        return false;


    }
};
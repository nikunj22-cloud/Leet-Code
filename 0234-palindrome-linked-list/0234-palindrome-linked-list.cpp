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
  //beacuse empty list b palindrom bnati h
  //recursion chlega head ->next jb tk head ka next null na ho
  //curr joh ki head pr h aage bdhta rhega recursion ka kuch ni h woh toh traverse krlega apne aap backtracking k through but curr ko compare krne k liye backtrack krna pdega
class Solution {
public:
    ListNode* curr;
    
    bool checkPalindrom(ListNode* head) {
        if(head == NULL)
            return true;
            
        bool check = checkPalindrom(head->next);
        if(head->val != curr->val) {  //false se hee check krenge kyoki curr head k last m phuch gya agr last wali value same nhi nikli toh aage bdn ka koi fayda nhi h isk=liye yhi se false return krdenge
            return false;
        }
        curr = curr->next;
        return check;  
    }
    bool isPalindrome(ListNode* head) {
        curr = head;
        return checkPalindrom(head);
    }
};
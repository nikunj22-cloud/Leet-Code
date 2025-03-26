/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  // Agar root null hai to return null
            return NULL;
        
        Node* leftmost = root;  // Har level ka leftmost node
        
        while (leftmost->left) {  // Jab tak left child hai
            Node* head = leftmost;
            
            while (head) {  // Current level traverse karo
                // Connection 1: Ek node ke bacchon ko jodo
                head->left->next = head->right;
                
                // Connection 2: Agar next node hai to uske saath jodo
                if (head->next) {
                    head->right->next = head->next->left;
                }
                
                head = head->next;  // Agle node pe jao
            }
            
            leftmost = leftmost->left;  // Next level pe jao
        }
        
        return root;
    }
};
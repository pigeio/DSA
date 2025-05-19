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
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;   // ① pointer to the successor
        node->val  = next->val;        // ② steal its value
        node->next = next->next;       // ③ bypass it
        delete next;     
    }
};
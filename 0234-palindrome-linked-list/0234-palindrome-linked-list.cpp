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
    ListNode* reverseLinkedList(ListNode* head){
        if(!head || !head->next){
            return head;
        }

        ListNode* last = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL ||head->next == NULL){
            return true;
        }
     ListNode* slow = head;
     ListNode* fast = head;
     ListNode* prev = NULL;

      while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
      }

      ListNode* tail = reverseLinkedList(slow);
      prev->next = NULL;

      while(tail != NULL && head != NULL){
        if(head->val != tail->val){
            return false;
        }
        tail = tail->next;
        head = head->next;
      }
      return true;
    }
};
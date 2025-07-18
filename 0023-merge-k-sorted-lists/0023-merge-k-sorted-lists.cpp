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
    ListNode* mergeTwoList(ListNode* L1 , ListNode* L2){
        if(!L1) return L2;
        if(!L2) return L1;

        if(L1->val < L2->val){
            L1->next = mergeTwoList(L1->next , L2);
            return L1;
        }else{
            L2->next = mergeTwoList(L2->next , L1);
            return L2;
        }
        return NULL;
    }

    ListNode* partionAndMerge(int start, int end ,vector<ListNode*>& lists){
        if(start == end) return lists[start];
        int mid = start + (end-start) /2;

        ListNode* L1 = partionAndMerge(start , mid , lists);
        ListNode* L2 = partionAndMerge(mid+1 ,end , lists);

        return mergeTwoList(L1 , L2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0) return NULL;

        return partionAndMerge(0, n-1, lists);
    }
};
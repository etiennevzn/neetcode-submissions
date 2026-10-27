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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;
        ListNode* kth;
        ListNode* groupNext;
        int groupCount = 1;

        while(1){
            groupCount = 1;
            kth = groupPrev->next;
            while(kth && groupCount < k){
                kth = kth->next;
                groupCount++;
            }
            if(!kth) break;

            groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* cur = groupPrev->next;
            while(groupCount > 0){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
                groupCount--;
            }

            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }

        return dummy->next;
    }
};

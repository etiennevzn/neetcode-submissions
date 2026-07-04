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
        ListNode* cur = head;
        int group = 0;

        while(cur && group < k){
            cur = cur->next;
            group++;
        }

        if(group == k){
            ListNode* prev = reverseKGroup(cur, k);
            cur = head;
            while(group-- > 0){
                ListNode* next = cur->next;
                cur->next = prev; 
                prev = cur;
                cur = next;
            }
            head = prev;
        }

        return head;
    }
};

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
        int groupCount = 0;
        ListNode* nextGroupHead = head;
        while(nextGroupHead && groupCount < k){
            nextGroupHead = nextGroupHead->next;
            groupCount++;
        }

        if(groupCount == k){
            ListNode* prev = reverseKGroup(nextGroupHead, k);
            ListNode* cur = head;
            while(groupCount > 0){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
                groupCount--;
            }
            head = prev;
        }

        return head;
    }
};

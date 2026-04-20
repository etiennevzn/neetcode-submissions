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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* remove = head;
        ListNode* curNode = head;

        for(int i = 0; i < n; i++){
            curNode = curNode->next;
        }            

        ListNode* prev = nullptr;
        while(curNode){
            curNode = curNode->next;
            prev = remove;
            remove = remove->next;
        }

        if(remove == head) return head->next;
        
        if(prev) prev->next = remove->next;
        return head;
    }
};

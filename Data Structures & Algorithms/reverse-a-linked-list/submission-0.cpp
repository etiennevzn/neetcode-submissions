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
    ListNode* reverseList(ListNode* head) {
        ListNode* curNode = head;
        ListNode* previousNode = nullptr;

        while(curNode != nullptr){
            ListNode* nextNode = curNode->next;
            curNode->next = previousNode;
            previousNode = curNode;
            curNode = nextNode;
        }

        return previousNode;
    }
};

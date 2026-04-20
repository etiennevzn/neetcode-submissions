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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*,int> count;
        ListNode* curNode = head;

        while(curNode){
            count[curNode]++;
            if(count[curNode] > 1) return true;
            curNode = curNode->next;
        }

        return false;
    }
};

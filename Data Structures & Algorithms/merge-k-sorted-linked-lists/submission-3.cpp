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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        ListNode* dummy = new ListNode(0);
        ListNode* curNode = dummy;

        while(true){
            int minValue = -1;
            for(int i = 0; i < lists.size(); ++i){
                if(!lists[i]) continue;
                if(minValue == -1 || lists[i]->val < lists[minValue]->val) minValue = i;
            }
            if(minValue == -1) break;

            curNode->next = lists[minValue];
            lists[minValue] = lists[minValue]->next;
            curNode = curNode->next;
        }

        return dummy->next;
    }
};

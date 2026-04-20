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
        if (lists.empty()) return nullptr;

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for(ListNode* head : lists){
            if(head){
                minHeap.push(head);
            }
        }

        while(!minHeap.empty()){
            ListNode* nextNode = minHeap.top();
            minHeap.pop();

            cur->next = nextNode;
            cur = cur->next;
            if(cur->next){
                minHeap.push(cur->next);
            }
        }

        return dummy->next;
    }
};

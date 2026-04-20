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
        ListNode* slow = head;
        ListNode* fast = head;
        int iter = 0;

        while(fast != nullptr){
            if(fast == slow && iter != 0) return true;

            if(fast->next){
                fast = fast->next->next;
            }else{
                fast = nullptr;
            }
            
            slow = slow->next;
            iter++;
        }

        return false; 
    }
};

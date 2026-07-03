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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int val1 = 0, val2 = 0;
        int carry = 0;
        int newCarry = 0;

        ListNode* dummy = new ListNode;
        ListNode* cur = dummy;
        while(cur1 || cur2){
            val1 = cur1 ? cur1->val : 0;
            val2 = cur2 ? cur2->val : 0;
            newCarry = 0;

            if(val1 + val2 + carry >= 10) newCarry = (val1+val2+carry)/10;
            int val = (val1+val2+carry)%10;
            cur->next = new ListNode(val);
            carry = newCarry;
            cur = cur->next;
            if(cur1) cur1 = cur1->next;
            if(cur2) cur2 = cur2->next;
        }

        if(carry != 0) cur->next = new ListNode(carry);

        return dummy->next;
    }
};

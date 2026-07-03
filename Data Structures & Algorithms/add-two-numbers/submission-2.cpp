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
        int carry = 0;
        int newCarry = 0;

        ListNode* dummy = new ListNode;
        ListNode* cur = dummy;
        while(cur1 && cur2){
            newCarry = 0;
            if(cur1->val + cur2->val + carry >= 10) newCarry = (cur1->val+cur2->val+carry)/10;
            int val = (cur1->val+cur2->val+carry)%10;
            cur->next = new ListNode(val);
            carry = newCarry;
            cur = cur->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        while(cur1){
            newCarry = 0;
            if(cur1->val + carry >= 10) newCarry = (cur1->val+carry)/10;
            int val = (cur1->val+carry)%10;
            cur->next = new ListNode(val);
            carry = newCarry;
            cur = cur->next;
            cur1 = cur1->next;
        }

        while(cur2){
            newCarry = 0;
            if(cur2->val + carry >= 10) newCarry = (cur2->val+carry)/10;
            int val = (cur2->val+carry)%10;
            cur->next = new ListNode(val);
            carry = newCarry;
            cur = cur->next;
            cur2 = cur2->next;
        }

        if(carry != 0) cur->next = new ListNode(carry);

        return dummy->next;
    }
};

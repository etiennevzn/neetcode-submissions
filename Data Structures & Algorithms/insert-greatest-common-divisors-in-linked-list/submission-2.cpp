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
private:
    int pgcd(int a, int b){
        if(b == 0) return a;
        return pgcd(b, a % b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head) return nullptr;
        ListNode* cur = head;
        while(cur->next){
            ListNode* next = cur->next;
            int divisor = pgcd(cur->val, cur->next->val);
            cur->next = new ListNode(divisor, next);
            cur = next;
        }
        return head;
    }
};
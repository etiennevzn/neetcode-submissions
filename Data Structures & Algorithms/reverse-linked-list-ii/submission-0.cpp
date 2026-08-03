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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = new ListNode(0, head);
        ListNode* next = nullptr;
        int count = 1;
        ListNode* cur = head;

        while(count < left){
            prev = cur;
            cur = cur->next;
            count++;
        }

        while(count < right){
            cur = cur->next;
            count++;
        }

        next = cur->next;

        ListNode* p = prev;
        cur = p->next;
        count = left;
        while(count <= right){
            ListNode* tmp = cur->next;
            cur->next = p;
            p = cur;
            cur = tmp;
            count++;
        }

        prev->next->next = next;
        prev->next = p;

        return left == 1 ? prev->next : head;
    }
};
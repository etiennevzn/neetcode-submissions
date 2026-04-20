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
    void reorderList(ListNode* head) {
        //Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reverse the second part of the list
        ListNode* head2 = slow->next;
        slow->next = nullptr;

        ListNode* previous = nullptr;
        while(head2 != nullptr){
            ListNode* next = head2->next;
            head2->next = previous;
            previous = head2;
            head2 = next;
        }

        //Merge the two lists
        ListNode* head1 = head;
        head2 = previous;
        while(head2){
            ListNode* next1 = head1->next;
            ListNode* next2 = head2->next;

            head1->next = head2;
            head2->next = next1;

            head1 = next1;
            head2 = next2;
        }
    }
};

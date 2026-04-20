class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode headTracker;
        ListNode* curNode = &headTracker;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                curNode->next = list1;
                list1 = list1->next;
            }else{
                curNode->next = list2;
                list2 = list2->next;
            }

            curNode = curNode->next;
        }

        if(list1 != nullptr){
            curNode->next = list1;
        }else{
            curNode->next = list2;
        }

        return headTracker.next;
    }
};
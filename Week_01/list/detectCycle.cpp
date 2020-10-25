/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* fast{head};
        ListNode* slow{head};
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) {
                ListNode* first{head};
                ListNode* second{fast};
                int count = 0;
                while (first != second) {
                    count++;
                    first = first->next;
                    second = second->next;
                }
                return first;
            }
        }
        return NULL;
    }
};
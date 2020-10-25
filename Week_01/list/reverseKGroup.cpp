
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
    pair<ListNode*,ListNode*> reverse(ListNode* head,ListNode* tail) {
                ListNode* last_target = tail->next;
                ListNode* core = head;
                while(last_target != tail ) {
                    ListNode* temp = core->next;
                    core->next = last_target;
                    last_target = core;
                    core = temp; 
                }
                return pair{tail,head};
            }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* begin_first = new ListNode(0);
        begin_first->next = head;
        ListNode* pre{begin_first};
        ListNode* tail{head};
        ListNode* nex;
        while(head) {
            tail = head;
            for(int i = 1 ; i< k;++i) {
                tail = tail->next;
                if(tail == NULL) return begin_first->next;
            }
            nex = tail->next;
            tie(head,tail) = reverse(head,tail);
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = nex;
        }
        return begin_first->next;
    }
};
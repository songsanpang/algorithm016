/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

////递归法
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if( head ==NULL || head->next == NULL) return head;
//         ListNode* p = head->next;
//         head->next = swapPairs(p->next);
//         p->next = head;
//         return p;
//     }
// };








//迭代法

class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL || head->next ==NULL) return head;
        ListNode* p = new ListNode;
        p->next = head;
        ListNode* cur = p;
        while(head !=NULL && head->next !=NULL) {
            ListNode* first = head;
            ListNode* second = head->next;
            first->next = second->next;
            second->next = first;
            cur->next = second;
            cur = first;
            head = first->next;
        }
        return p->next;
    }
};
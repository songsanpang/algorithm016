/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// //迭代法
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* pre = head;
//         ListNode* cur = NULL;
//         while(pre != NULL) {
//             ListNode* temp = pre->next;
//             pre->next = cur;
//             cur = pre;
//             pre = temp;
//         }
//         return cur;
//     }
// };






// 递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL,head);
    }
    ListNode* reverse(ListNode* pre ,ListNode* cur){
        if (cur == NULL) {
            return pre ;
        }
        ListNode * t = cur->next;
        cur->next = pre;
        pre = cur;
        cur = reverse(pre,t);
        return cur;
    }
};







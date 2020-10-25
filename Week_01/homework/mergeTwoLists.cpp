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


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* Result = new ListNode(222);
//         ListNode* Temp = Result;
//         while(l1 != nullptr && l2 != nullptr){
//             if(l1->val <= l2->val) {
//                 Temp->next = l1;
//                 l1 = l1->next;
//                 Temp = Temp->next;
//             }
//             else{
//                 Temp->next = l2;
//                 l2 = l2->next;
//                 Temp = Temp->next;
//             }
            
//         }
//         if(l1 == nullptr) {
//             Temp->next = l2;
//         }
//         else {
//             Temp->next = l1;
//         }
//         return Result->next;
//     }
// };


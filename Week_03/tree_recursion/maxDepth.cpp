/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  正向递归
// class Solution {
// public:
//     int deep = 0;
//     int max = 0; 
//     int maxDepth(TreeNode* root) {
//         if(!root) {
//             if(deep>max) max = deep;
//             return deep;
//         }
//         ++deep;
//         int i=deep;
//         maxDepth(root->left);
//         deep = i;
//         maxDepth(root->right);
//         return max;
//     }
// };
// 反向递归
class Solution {
public: 
    int maxDepth(TreeNode* root) {
       return root == nullptr ?  0 :  max(maxDepth(root->left)+1,maxDepth(root->right)+1); 
    }
};

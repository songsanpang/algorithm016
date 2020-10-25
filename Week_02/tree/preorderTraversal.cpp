/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//  //递归法
// class Solution {
// public:
//     void traversal(TreeNode* root, vector<int>& temp) {
//         temp.push_back(root->val);
//         if(root->left) traversal(root->left ,temp);
//         if(root->right) traversal(root->right ,temp);
//         return;
//     }
//     vector<int> preorderTraversal(TreeNode* root) {        
//         vector<int> res;
//         if(!root) return res;
//         traversal(root,res);
//         return res;
//     }
// };

//迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {        
       stack<TreeNode *> st;
       vector<int> res;
       if(root) st.push(root);
       while(!st.empty()) {
           TreeNode* node = st.top();
           if(node != nullptr) {
               st.pop();
               if(node->right) st.push(node->right);
               if(node->left) st.push(node->left);
               st.push(node);
               st.push(nullptr);
           }
           else {
               st.pop();
               node = st.top();
               st.pop();
               res.push_back(node->val);
           }
       }
       return res;
    }
};
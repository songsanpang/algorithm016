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
class Solution {
public:
    void orderTraversal(TreeNode* root ,vector<int>& recoder) {
            if(root->left != nullptr) orderTraversal(root->left,recoder);
            recoder.push_back(root->val);
            if(root->right != nullptr) orderTraversal(root->right,recoder);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        orderTraversal(root,res);
        return res;
    }
};
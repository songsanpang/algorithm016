/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* note = new TreeNode(0); 
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(root) {
            note->left = root->left;
            root->left = root->right;
            root->right = note->left;
        }
        if(root->left ){
            invertTree(root->left);
        }
        if(root->right ){
            invertTree(root->right);
        }
        return root;
    }
};
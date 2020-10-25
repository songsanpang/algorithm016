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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int num = preorder.size();
        if(!num) return nullptr;
        TreeNode* root = new TreeNode{preorder[0]} ;
        vector<int> preorder_left,preorder_right,inorder_left,inorder_right;
        //找到左子树的中序遍历
        int i{0};
        for(;i<num;++i) {
            if(inorder[i] == preorder[0]) break;
            inorder_left.push_back(inorder[i]); 
        }
        //找到右子树的中序遍历
        for(++i;i<num;++i) {
            inorder_right.push_back(inorder[i]);
        }
        //找到左子树的前序遍历
        for(i = 1;i<=inorder_left.size();++i) {
            preorder_left.push_back(preorder[i]); 
        }
        //找到右子树的前序遍历
        for( ;i < num;++i) {
            preorder_right.push_back(preorder[i]); 
        }
        root->left = buildTree(preorder_left,inorder_left);
        root->right = buildTree(preorder_right,inorder_right);
        return root;
    }
};
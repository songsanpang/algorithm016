class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(root->left && root->right) return  min(minDepth(root->left)+1,minDepth(root->right)+1);
        return 1+max(minDepth(root->left),minDepth(root->right));
    }
};